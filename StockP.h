#include <vector>
#include <random>
#include <fstream>
#include <iostream>
using namespace std ;

#ifndef StockP_h
#define StockP_h

class StockP
{
protected:

	double m_s0, m_r, m_theta, m_sigma, m_q ;

public:

	StockP(double s0, double r, double q, double theta, double sigma):m_s0(s0), m_r(r), m_theta(theta), m_sigma(sigma), m_q(q)
	{}

	virtual double GetFutVal(double T)=0 ;
	virtual vector<double> GeneratePath(double T)=0 ;
	double GetRate() const ;
	double GetSpot() const ;
	double GetDiv() const ;

} ;

class GBM:public StockP
{
private:

public:
	
	GBM(double s0, double r, double q, double sigma):StockP(s0,r,q,r-q,sigma)
	{}

	double GetFutVal(double T) ;
	vector<double> GeneratePath(double T) ;
};

class VG:public StockP
{
private:

	double m_nu ;

public:
	
	VG(double s0, double r, double q, double theta, double sigma, double nu):StockP(s0,r,q,theta,sigma), m_nu(nu)
	{}

	double VGproc(double T) ;
	double GetFutVal(double T) ;
	vector<double> GeneratePath(double T) ;
};

#endif
