#include "stats1.h"
#include <cmath>
#include <iostream>
using namespace std ;

void stats1::add(double x)
{
	sum+=x ;
	sqsum+=(x*x) ;
	count++ ;
}

double stats1::mean() const
{
	if (count==0) 
	{
		cout << "ERROR: Invlaid count!" << endl ;
		exit (EXIT_FAILURE) ;
	}

	else return sum/count ;
}

double stats1::stDev() const
{
	return sqrt((sqsum/count) - (pow(mean(),2.0))) ;
}

double stats1::stdError() 
{
	return stDev()/(sqrt(count-1.0)) ;
}

double stats1::stdErrorPer() 
{
	return (stdError()/mean())*100 ;
}

int stats1::getCount() const
{
	return count ;
}

