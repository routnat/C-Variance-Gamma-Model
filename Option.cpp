#include "Option.h"

// intermediary for implied vol
class CallIntermediary: public EurCall
{
   private:
      double S0,r,q;
   public:
      CallIntermediary(double S0_, double r_, double q_, double T_, double K_):EurCall(T_,K_),S0(S0_),r(r_),q(q_)  
	  {}

      double Value(double sigma)
      {
         return PriceByBSFormula(S0,sigma,r,q);
      }

      double Deriv(double sigma)
      {
         return VegaByBSFormula(S0,sigma,r);
      }
};

class PutIntermediary: public EurPut
{
   private:
      double S0,r,q;
   public:
      PutIntermediary(double S0_, double r_, double q_, double T_, double K_):EurPut(T_,K_),S0(S0_),r(r_),q(q_)  
	  {}

      double Value(double sigma)
      {
         return PriceByBSFormula(S0,sigma,r,q);
      }

      double Deriv(double sigma)
      {
         return VegaByBSFormula(S0,sigma,r);
      }
};

double Option::N(double x)
{
   double gamma = 0.2316419;     double a1 = 0.319381530;
   double a2    =-0.356563782;   double a3 = 1.781477937;
   double a4    =-1.821255978;   double a5 = 1.330274429;
   double pi    = 4.0*atan(1.0); double k  = 1.0/(1.0+gamma*x);
  
   if (x>=0.0)
   {
      return 1.0-((((a5*k+a4)*k+a3)*k+a2)*k+a1)*k*exp(-x*x/2.0)/sqrt(2.0*pi);
   }
   
   else return 1.0-N(-x) ;
}

double Option::d_plus(double S0, double sigma, double r)
{
    return (log(S0/m_K)+(r+0.5*pow(sigma,2.0))*m_T)/(sigma*sqrt(m_T)) ;
}

double Option::d_minus(double S0, double sigma, double r)
{
   return d_plus(S0,sigma,r)-sigma*sqrt(m_T) ;
}

//Price using monte carlo method
double Option::PriceByMC(StockP &obj, int paths)
{
	double st ; 

	stats1 stat ;

	if(paths==0)
	{
		for(int i=0 ;i<10 ;i++)
		{
			st=obj.GetFutVal(m_T) ;
			stat.add(Payoff(st)) ;
		}
	
		while(stat.stdErrorPer()>0.1)
		{
			st=obj.GetFutVal(m_T) ;
			stat.add(Payoff(st)) ;
		}
	}
	else
	{
		for(int i=0 ;i<paths ;i++)
		{
			st=obj.GetFutVal(m_T) ;
			stat.add(Payoff(st)) ;
		}
	
	}

	//cout << "# Paths: " << stat.getCount() << endl ;
	cout << "Error(%): " << stat.stdErrorPer() << endl ;

	return exp(-obj.GetRate()*m_T)*stat.mean() ;
}

double Option::PriceByMC(StockP &obj, int paths, double k)
{
	double st ; 

	stats1 stat ;

	if(paths==0)
	{
		for(int i=0 ;i<10 ;i++)
		{
			st=obj.GetFutVal(m_T) ;
			stat.add(Payoff(st,k)) ;
		}
	
		while(stat.stdErrorPer()>0.1)
		{
			st=obj.GetFutVal(m_T) ;
			stat.add(Payoff(st,k)) ;
		}
	}
	else
	{
		for(int i=0 ;i<paths ;i++)
		{
			st=obj.GetFutVal(m_T) ;
			stat.add(Payoff(st,k)) ;
		}
	
	}

	//cout << "# Paths: " << stat.getCount() << endl ;
	cout << "Error(%): " << stat.stdErrorPer() << endl ;

	return exp(-obj.GetRate()*m_T)*stat.mean() ;
}

//black scholes price (call)
double EurCall::PriceByBSFormula(double S0, double sigma, double r, double q)
{
	return S0*exp(-q*m_T)*N(d_plus(S0,sigma,r))-m_K*exp(-r*m_T)*N(d_minus(S0,sigma,r)) ;
}

//black scholes vega (call)
double EurCall::VegaByBSFormula(double S0,double sigma, double r)
{
	double pi=4.0*atan(1.0) ;
	
	return S0*exp(-d_plus(S0,sigma,r)*d_plus(S0,sigma,r)/2)*sqrt(m_T)/sqrt(2.0*pi) ;
}

//call payoff
double EurCall::Payoff(double z)
{
	return (z>m_K) ? z-m_K : 0.0 ;
}

//call payoff for any k
double EurCall::Payoff(double z, double k)
{
	return (z>k) ? z-k : 0.0 ;
}

//call implied volatility
double EurCall::ImpliedVol(double tgt, double S0,double r, double div,double T,double K)
{
	double acc=0.001 ;
	CallIntermediary C(S0,r,div,T,K) ;
	return SolveByBisect(&C,tgt,0.0,1.0,acc) ;
	//return SolveByNR(&C,tgt,0.5,acc) ;
}

//Generate Volatility Smile (call)
map<double,double> EurCall::VolSmile(StockP &obj, double kmin, double kmax, int n)
{
	double acc=0.01, dk=(kmax-kmin)/(n-1) ;

	map<double,double> smilemap ;

	double k=kmin, tgt, spot=obj.GetSpot(), rate=obj.GetRate(),dividend=obj.GetDiv()  ;

	for(int i=1 ; i<=n ; i++)
	{
		tgt=PriceByMC(obj,10000000,k) ;
		smilemap.insert( pair<double,double>(k, ImpliedVol(tgt,spot,rate,dividend,m_T,k))) ;
		k+=dk ;
	}

	return smilemap ;
}

//black scholes price (put)
double EurPut::PriceByBSFormula(double S0, double sigma, double r, double q)
{
   return m_K*exp(-r*m_T)*N(-d_minus(S0,sigma,r)) - S0*exp(-q*m_T)*N(-d_plus(S0,sigma,r)) ;
}

//black scholes vega (put)
double EurPut::VegaByBSFormula(double S0,double sigma, double r)
{
	double pi=4.0*atan(1.0) ;
	
	return 0 ;
}

//put payoff
double EurPut::Payoff(double z)
{
	return (m_K>z) ? m_K-z : 0.0 ;
}

//put payoff for any k
double EurPut::Payoff(double z, double k)
{
	return (k>z) ? k-z : 0.0 ;
}

//put implied volatility
double EurPut::ImpliedVol(double tgt, double S0,double r, double div,double T,double K)
{
	double acc=0.01 ;
	PutIntermediary P(S0,r,div,T,K) ;
	return SolveByBisect(&P,tgt,0.0,1.0,acc) ;
}