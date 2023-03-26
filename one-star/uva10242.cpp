#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		vector<double> xs={x1,x2,x3,x4};
		vector<double> ys={y1,y2,y3,y4};
		vector<pair<double, double>> ep;
		pair<double, double> cp;
		for(int i=0; i<4; i++)
		{
			for(int j=i+1; j<4; j++)
			{
				if(xs[i]==xs[j]&&ys[i]==ys[j])cp=make_pair(xs[i], ys[i]);
			}
			
		}
		for(int i=0; i<4; i++)
		{
			if(xs[i]!=cp.first||ys[i]!=cp.second) ep.push_back(make_pair(xs[i], ys[i]));
		}
		double ax=ep[0].first;
		double ay=ep[0].second;
		double bx=cp.first;
		double by=cp.second;
		double cx=ep[1].first;
		double cy=ep[1].second;
		
		double dx=ax-bx;
		double dy=ay-by;
		printf("%0.3lf %0.3lf\n", cx+dx, cy+dy);
	}

	return 0;
}