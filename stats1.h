#ifndef stats1_h
#define stats1_h

class stats1
{
private:

	int count ;
	double sum, sqsum ;

public:

	stats1():count(0),sum(0),sqsum(0)
	{}

	void add(double x) ;
	double mean() const ;
	double stDev() const ;
	double stdError() ;
	double stdErrorPer() ;
	int getCount() const ;

} ;
#endif