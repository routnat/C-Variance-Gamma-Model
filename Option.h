#include "StockP.h"
#include "stats1.h"
#include "Solver03.h" 
#include <cmath>
#include <map>
#include <iostream>
using namespace std ;

#ifndef Option_h
#define Option_h

class Option
{
protected:

	double m_T, m_K ;
	double N(double x) ;
	double Psi(double a, double b, double gamma) ;
	double Phi() ;
	double d_plus(double S0, double sigma, double r) ;
	double d_minus(double S0, double sigma, double r) ;
	
public:

	Option(double T_, double K_):m_T(T_), m_K(K_) 
	{
		if(T_<=0 || K_<=0) 
		{
		cout << "ERROR: Invlaid Input!" << endl ;
		exit (EXIT_FAILURE) ;
		}
	}

	double PriceByMC(StockP &obj, int paths) ;
	double PriceByMC(StockP &obj, int paths, double k) ;
	
	virtual double ImpliedVol(double tgt, double S0,double r, double div,double T,double K)=0 ;
	virtual double PriceByBSFormula(double S0,double sigma, double r, double q)=0 ;
	virtual double VegaByBSFormula(double S0,double sigma, double r)=0 ;
	virtual double Payoff(double z)=0 ;
	virtual double Payoff(double z, double k)=0 ;

};

class EurCall:public Option
{
private:

public:
	
	EurCall(double T_, double K_):Option(T_,K_)
	{}

	double PriceByBSFormula(double S0,double sigma, double r, double q) ;
	double VegaByBSFormula(double S0,double sigma, double r) ;
	double Payoff(double z) ;
	double Payoff(double z, double k) ;
	double ImpliedVol(double tgt, double S0,double r, double div,double T,double K) ;
	map<double,double> VolSmile(StockP &obj, double kmin, double kmax, int n) ;
};
	

class EurPut:public Option
{
private:

public:
	
	EurPut(double T_, double K_):Option(T_,K_)
	{}

	double PriceByBSFormula(double S0,double sigma, double r, double q) ;
	double VegaByBSFormula(double S0,double sigma, double r) ;
	double Payoff(double z) ;
	double Payoff(double z, double k) ;
	double ImpliedVol(double tgt, double S0,double r, double div,double T,double K) ;

};

#endif

