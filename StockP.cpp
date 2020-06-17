#include "StockP.h" 

double StockP::GetRate() const
{
	return m_r ;
}

double StockP::GetSpot() const
{
	return m_s0 ;
}

double StockP::GetDiv() const
{
	return m_q ;
}

//Generates VG value
double VG::VGproc(double T)
{
	random_device rd ;
	mt19937 gen(rd()) ;
	//gamma_distribution<double> gamma(T/m_nu,1/nu) ; //nu is the variance rate
	gamma_distribution<double> gamma(T/m_nu,m_nu) ; //nu is the variance
	normal_distribution<double> normal(0.0,1.0);
	
	double g=gamma(gen) ;

	return (m_theta*g) + (m_sigma*sqrt(g)*normal(gen)) ;
}

//returns the stock value at time T
double VG::GetFutVal(double T)
{
	double w=(1/m_nu)*log(1-(m_theta*m_nu)-(m_sigma*m_sigma*m_nu)/2), c1=(m_r-m_q)*T, c2=w*T ;

	return m_s0*exp(c1 + c2 + VGproc(T)) ;
}

//generates daily path to time T
vector<double> VG::GeneratePath(double T)
{
	double dt=1.0/52.0 ;
	double n=T/dt ;

	vector<double> path ;
	path.push_back(m_s0) ;

	double g=0.0, w=(1/m_nu)*log(1-(m_theta*m_nu)-(m_sigma*m_sigma*m_nu)/2), c1=(m_r-m_q)*dt, c2=w*dt ;

	for(int i=0 ;i<=n-1 ;i++)
	{
		g=VGproc(dt) ;
		path.push_back((path.back())*exp(c1+c2+g)) ;
	}

	return path ;
}

//returns the stock value at time T
double GBM::GetFutVal(double T)
{
	/*
	double c1=(m_theta-(0.5*m_sigma*m_sigma))*T, c2=sqrt(T)*m_sigma ;

	random_device gen ;
	normal_distribution<double> normal(0.0,1.0) ;

	return m_s0*exp(c1 + c2*normal(gen)) ;
	*/
	
	double dt=1.0/365.0 ;
	double n=T/dt ;

	double s=m_s0 ;

	double c1=(m_theta-(0.5*m_sigma*m_sigma))*dt, c2=sqrt(dt)*m_sigma ; ;
	
	random_device rd ;
	mt19937 gen(rd()) ;

	normal_distribution<double> normal(0.0,1.0) ;

	for(int i=0 ;i<=n-1 ;i++)
	{
		s=s*exp(c1 + c2*normal(gen)) ;
	}
	
	return s ;
}

//generates daily path to time T
vector<double> GBM::GeneratePath(double T)
{
	double dt=1.0/52.0 ;
	double n=T/dt ;

	vector<double> path ;
	path.push_back(m_s0) ;

	double c1=(m_theta-(0.5*m_sigma*m_sigma))*dt, c2=sqrt(dt)*m_sigma ; ;

	random_device rd ;
	mt19937 gen(rd()) ;

	normal_distribution<double> normal(0.0,1.0) ;

	for(int i=0 ;i<=n-1 ;i++)
	{
		path.push_back((path.back())*exp(c1 + c2*normal(gen))) ;
	}

	return path ;
}
