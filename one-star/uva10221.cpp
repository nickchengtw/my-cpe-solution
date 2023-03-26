#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


int main()
{
	int s, a;
	string unit;
	while(cin>>s>>a>>unit)
	{
		int r = s+6440;
		double deg = (unit=="deg")?a:(a/60.0);
		//cout<<sin(30)<<endl;
		double clen = sin(deg*M_PI/180.0/2.0)*r*2;
		double alen = deg/360.0 * 2 * M_PI * r;
		
		printf("%.6lf %.6lf\n", alen, clen);
	}

	return 0;
}