#include "Option.h" 
#include <cmath> 
#include <iostream> 
using namespace std ;

//tools
void WriteVectorToStream(vector<double> v , ostream& os) ;
void WriteMapToStream(map<double, double> m , ostream& os) ;

int main()
{
	double S0=1000.0, K=1000.0, T=0.3, sigma=0.180862, vgsigma=0.2, r=0.05, theta=-0.3, nu=0.3, div=0.0 ;
	int paths=1000000 ;
	
	
	EurCall ec(T, K) ;
	VG vg(S0,r,div,theta,vgsigma,nu) ;
	GBM gbm(S0,r,div,sigma) ;

	/*
	//cout << "BS: " << ec.PriceByBSFormula(S0,sigma,r,div) << endl ;
	//cout << "GBM: " << ec.PriceByMC(gbm,paths) << endl ;
	cout << "VG: " << ec.PriceByMC(vg600,paths) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg600,paths),600,r,div,T,K) << endl ;
	

	cout << "VG: " << ec.PriceByMC(vg1400,paths) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg1400,paths),1400,r,div,T,K) << endl ;
	*/
	/*
	VG vg(S0,r,div,theta,vgsigma,nu) ;

	GBM gbm425(S0,r,div,0.527782) ;
	GBM gbm430(S0,r,div,0.487779) ;
	GBM gbm435(S0,r,div,0.448993) ;
	GBM gbm440(S0,r,div,0.374433) ;
	GBM gbm445(S0,r,div,0.337273) ;
	GBM gbm450(S0,r,div,0.302713) ;
	GBM gbm455(S0,r,div,0.315577) ;
	GBM gbm460(S0,r,div,0.28742) ;
	GBM gbm465(S0,r,div,0.26165) ;
	GBM gbm470(S0,r,div,0.237993) ;
	GBM gbm475(S0,r,div,0.216719) ;
	GBM gbm480(S0,r,div,0.197852) ;
	GBM gbm485(S0,r,div,0.180862) ;
	GBM gbm490(S0,r,div,0.165489) ;
	GBM gbm495(S0,r,div,0.152067) ;
	EurCall ec425(T, 425.0) ;
	EurCall ec430(T, 430.0) ;
	EurCall ec435(T, 435.0) ;
	EurCall ec440(T, 440.0) ;
	EurCall ec445(T, 445.0) ;
	EurCall ec450(T, 450.0) ;
	EurCall ec455(T, 455.0) ;
	EurCall ec460(T, 460.0) ;
	EurCall ec465(T, 465.0) ;
	EurCall ec470(T, 470.0) ;
	EurCall ec475(T, 475.0) ;
	EurCall ec480(T, 480.0) ;
	EurCall ec485(T, 485.0) ;
	EurCall ec490(T, 490.0) ;
	EurCall ec495(T, 495.0) ;

	cout << "K\tVG\tgbm" << endl ;
	cout << "425\t" << ec425.PriceByMC(vg,paths) << "\t" << ec425.PriceByMC(gbm425,paths) << endl ; 
	cout << "430\t" << ec430.PriceByMC(vg,paths) << "\t" << ec430.PriceByMC(gbm430,paths) << endl ; 
	cout << "435\t" << ec435.PriceByMC(vg,paths) << "\t" << ec435.PriceByMC(gbm435,paths) << endl ;
	cout << "440\t" << ec440.PriceByMC(vg,paths) << "\t" << ec440.PriceByMC(gbm440,paths) << endl ; 
	cout << "445\t" << ec445.PriceByMC(vg,paths) << "\t" << ec445.PriceByMC(gbm445,paths) << endl ;
	cout << "450\t" << ec450.PriceByMC(vg,paths) << "\t" << ec450.PriceByMC(gbm450,paths) << endl ; 
	cout << "455\t" << ec455.PriceByMC(vg,paths) << "\t" << ec455.PriceByMC(gbm455,paths) << endl ; 
	cout << "460\t" << ec460.PriceByMC(vg,paths) << "\t" << ec460.PriceByMC(gbm460,paths) << endl ;
	cout << "465\t" << ec465.PriceByMC(vg,paths) << "\t" << ec465.PriceByMC(gbm465,paths) << endl ;
	cout << "470\t" << ec470.PriceByMC(vg,paths) << "\t" << ec470.PriceByMC(gbm470,paths) << endl ; 
	cout << "475\t" << ec475.PriceByMC(vg,paths) << "\t" << ec475.PriceByMC(gbm475,paths) << endl ;
	cout << "480\t" << ec480.PriceByMC(vg,paths) << "\t" << ec480.PriceByMC(gbm480,paths) << endl ; 
	cout << "485\t" << ec485.PriceByMC(vg,paths) << "\t" << ec485.PriceByMC(gbm485,paths) << endl ;
	cout << "490\t" << ec490.PriceByMC(vg,paths) << "\t" << ec490.PriceByMC(gbm490,paths) << endl ; 
	cout << "495\t" << ec495.PriceByMC(vg,paths) << "\t" << ec495.PriceByMC(gbm495,paths) << endl ;
	*/
	/*
	EurCall ec(T, K) ;
	VG vg80(0.8*S0,r,div,theta,vgsigma,nu) ;
	VG vg84(0.84*S0,r,div,theta,vgsigma,nu) ;
	VG vg88(0.88*S0,r,div,theta,vgsigma,nu) ;
	VG vg92(0.92*S0,r,div,theta,vgsigma,nu) ;
	VG vg96(0.96*S0,r,div,theta,vgsigma,nu) ;
	VG vg100(1.0*S0,r,div,theta,vgsigma,nu) ;
	VG vg104(1.04*S0,r,div,theta,vgsigma,nu) ;
	VG vg108(1.08*S0,r,div,theta,vgsigma,nu) ;
	VG vg112(1.12*S0,r,div,theta,vgsigma,nu) ;
	VG vg116(1.16*S0,r,div,theta,vgsigma,nu) ;
	VG vg120(1.2*S0,r,div,theta,vgsigma,nu) ;

	cout << "S\tvg" << endl ;
	cout << 0.8*S0 << "\t" << ec.PriceByMC(vg80,paths) << endl ;
	cout << 0.84*S0 << "\t" << ec.PriceByMC(vg84,paths) << endl ;
	cout << 0.88*S0 << "\t" << ec.PriceByMC(vg88,paths) << endl ;
	cout << 0.92*S0 << "\t" << ec.PriceByMC(vg92,paths) << endl ;
	cout << 0.96*S0 << "\t" << ec.PriceByMC(vg96,paths) << endl ;
	cout << 1.0*S0 << "\t" << ec.PriceByMC(vg100,paths) << endl ;
	cout << 1.04*S0 << "\t" << ec.PriceByMC(vg104,paths) << endl ;
	cout << 1.08*S0 << "\t" << ec.PriceByMC(vg108,paths) << endl ;
	cout << 1.12*S0 << "\t" << ec.PriceByMC(vg112,paths) << endl ;
	cout << 1.16*S0 << "\t" << ec.PriceByMC(vg116,paths) << endl ;
	cout << 1.20*S0 << "\t" << ec.PriceByMC(vg120,paths) << endl ;
	
	/*
	//Apple
	//market imp vol
	cout << ec.ImpliedVol(45.2,S0,r,div,T,425.0) << endl ;
	cout << ec.ImpliedVol(41.55,S0,r,div,T,430.0) << endl ;
	cout << ec.ImpliedVol(38.1,S0,r,div,T,435.0) << endl ;
	cout << ec.ImpliedVol(34.7,S0,r,div,T,440.0) << endl ;
	cout << ec.ImpliedVol(31.6,S0,r,div,T,445.0) << endl ;
	cout << ec.ImpliedVol(28.675,S0,r,div,T,450.0) << endl ;
	cout << ec.ImpliedVol(25.875,S0,r,div,T,455.0) << endl ;
	cout << ec.ImpliedVol(23.325,S0,r,div,T,460.0) << endl ;
	cout << ec.ImpliedVol(20.95,S0,r,div,T,465.0) << endl ;
	cout << ec.ImpliedVol(18.725,S0,r,div,T,470.0) << endl ;
	cout << ec.ImpliedVol(16.725,S0,r,div,T,475.0) << endl ;
	cout << ec.ImpliedVol(14.9,S0,r,div,T,480.0) << endl ;
	cout << ec.ImpliedVol(13.2,S0,r,div,T,485.0) << endl ;
	cout << ec.ImpliedVol(11.7,S0,r,div,T,490.0) << endl ;
	cout << ec.ImpliedVol(10.375,S0,r,div,T,495.0) << endl ;
	*/
	/*
	//simulation
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,425.0),S0,r,div,T,425.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,430.0),S0,r,div,T,430.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,435.0),S0,r,div,T,435.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,440.0),S0,r,div,T,440.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,445.0),S0,r,div,T,445.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,450.0),S0,r,div,T,450.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,455.0),S0,r,div,T,455.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,460.0),S0,r,div,T,460.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,465.0),S0,r,div,T,465.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,470.0),S0,r,div,T,470.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,475.0),S0,r,div,T,475.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,480.0),S0,r,div,T,480.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,485.0),S0,r,div,T,485.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,490.0),S0,r,div,T,490.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,495.0),S0,r,div,T,495.0) << endl ;
	*/
	/*
	//Microsoft
	//market imp vol
	cout << ec.ImpliedVol(4.075,S0,r,div,T,29.0) << endl ;
	cout << ec.ImpliedVol(3.25,S0,r,div,T,30.0) << endl ;
	cout << ec.ImpliedVol(2.525,S0,r,div,T,31.0) << endl ;
	cout << ec.ImpliedVol(1.895,S0,r,div,T,32.0) << endl ;
	cout << ec.ImpliedVol(1.38,S0,r,div,T,33.0) << endl ;
	cout << ec.ImpliedVol(0.975,S0,r,div,T,34.0) << endl ;
	cout << ec.ImpliedVol(0.67,S0,r,div,T,35.0) << endl ;
	cout << ec.ImpliedVol(0.45,S0,r,div,T,36.0) << endl ;
	cout << ec.ImpliedVol(0.3,S0,r,div,T,37.0) << endl ;
	cout << ec.ImpliedVol(0.205,S0,r,div,T,38.0) << endl ;
	cout << ec.ImpliedVol(0.14,S0,r,div,T,39.0) << endl ;
	cout << ec.ImpliedVol(0.095,S0,r,div,T,40.0) << endl ;
	*/
	/*
	//simulation
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,31.0),S0,r,div,T,31.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,31.5),S0,r,div,T,31.5) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,32.0),S0,r,div,T,32.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,32.5),S0,r,div,T,32.5) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,33.0),S0,r,div,T,33.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,33.5),S0,r,div,T,33.5) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,34.0),S0,r,div,T,34.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,34.5),S0,r,div,T,34.5) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,35.0),S0,r,div,T,35.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,35.5),S0,r,div,T,35.5) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,36.0),S0,r,div,T,36.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,36.5),S0,r,div,T,36.5) << endl ;
	*/
	/*
	//cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,28.0),S0,r,div,T,28.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,29.0),S0,r,div,T,29.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,30.0),S0,r,div,T,30.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,31.0),S0,r,div,T,31.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,32.0),S0,r,div,T,32.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,33.0),S0,r,div,T,33.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,34.0),S0,r,div,T,34.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,35.0),S0,r,div,T,35.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,36.0),S0,r,div,T,36.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,37.0),S0,r,div,T,37.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,38.0),S0,r,div,T,38.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,39.0),S0,r,div,T,39.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,40.0),S0,r,div,T,40.0) << endl ;
	*/
	/*
	//Google
	//market imp vol
	cout << ec.ImpliedVol(53.3,S0,r,div,T,860.0) << endl ;
	cout << ec.ImpliedVol(50.15,S0,r,div,T,865.0) << endl ;
	cout << ec.ImpliedVol(47.05,S0,r,div,T,870.0) << endl ;
	cout << ec.ImpliedVol(43.95,S0,r,div,T,875.0) << endl ;
	cout << ec.ImpliedVol(41.0,S0,r,div,T,880.0) << endl ;
	cout << ec.ImpliedVol(38.15,S0,r,div,T,885.0) << endl ;
	cout << ec.ImpliedVol(35.45,S0,r,div,T,890.0) << endl ;
	cout << ec.ImpliedVol(32.95,S0,r,div,T,895.0) << endl ;
	cout << ec.ImpliedVol(30.5,S0,r,div,T,900.0) << endl ;
	cout << ec.ImpliedVol(28.2,S0,r,div,T,905.0) << endl ;
	cout << ec.ImpliedVol(26.05,S0,r,div,T,910.0) << endl ;
	cout << ec.ImpliedVol(23.85,S0,r,div,T,915.0) << endl ;
	cout << ec.ImpliedVol(22.0,S0,r,div,T,920.0) << endl ;
	cout << ec.ImpliedVol(20.15,S0,r,div,T,925.0) << endl ;
	cout << ec.ImpliedVol(18.4,S0,r,div,T,930.0) << endl ;
	*/
	/*
	//simulation
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,860.0),S0,r,div,T,860.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,865.0),S0,r,div,T,865.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,870.0),S0,r,div,T,870.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,875.0),S0,r,div,T,875.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,880.0),S0,r,div,T,880.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,885.0),S0,r,div,T,885.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,890.0),S0,r,div,T,890.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,895.0),S0,r,div,T,895.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,900.0),S0,r,div,T,900.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,905.0),S0,r,div,T,905.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,910.0),S0,r,div,T,910.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,915.0),S0,r,div,T,915.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,920.0),S0,r,div,T,920.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,925.0),S0,r,div,T,925.0) << endl ;
	cout << ec.ImpliedVol(ec.PriceByMC(vg,paths,930.0),S0,r,div,T,930.0) << endl ;
	*/
	
	ofstream write("VolSmile.csv") ;
	
	if(!write)
	{
		cout << "Error writing file!" << endl ;
		return -1 ;
	}

	double kmin=S0*0.8, kmax=S0*1.2 ;

	map<double, double> volsmile ;
	volsmile=ec.VolSmile(vg,kmin,kmax,11) ;
	WriteMapToStream(volsmile,write) ;

	cout << "Complete!" << endl ;
	write.close() ;
	
	/*
	ofstream write("vg.csv") ;
	
	if(!write)
	{
		cout << "Error writing file!" << endl ;
		return -1 ;
	}
	
	WriteVectorToStream(vg.GeneratePath(T),write) ;

	cout << "Complete!" << endl ;
	write.close() ;
	*/

	return 0 ;
}

void WriteMapToStream(map<double, double> m , ostream& os)
{
	typedef map<double, double>::const_iterator Iterator;

	for (Iterator i = m.begin(); i != m.end(); i++)
	{
		
		os << i->first << "," << i->second << endl ;
	}

}

void WriteVectorToStream(vector<double> v , ostream& os)
{
	for(int i=0 ; i<v.size() ; i++)
	{
		os << v[i] << endl ;
	}

	os << endl ;
}