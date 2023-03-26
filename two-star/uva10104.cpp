#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	int tmp;
	while(b>0)
	{
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}

pair<int, int> xy(int a, int b)
{
		int x=0;
		int y=0;
		for(int i=1; true; i++)
		{
			for(int j=0; j<i; j++)
			{
				x=j;
				y=i-j;
				if(a*x+b*y==1) return make_pair(x, y);
				x=-j;
				if(a*x+b*y==1) return make_pair(x, y);
			}
			
			x=i;
			y=0;
			if(a*x+b*y==1) return make_pair(x, y);
			x=-i;
			y=0;
			if(a*x+b*y==1) return make_pair(x, y);
			
			for(int j=i-1; j>=0; j--)
			{
				x=j;
				y=j-i;
				if(a*x+b*y==1) return make_pair(x, y);
				x=-j;
				if(a*x+b*y==1) return make_pair(x, y);
			}
		}
}

int main()
{
	int a, b;
	while(cin>>a>>b)
	{
		int d=gcd(a, b);
		a/=d;
		b/=d;
		pair<int, int> xyp=xy(a, b);
		printf("%d %d %d\n", xyp.first, xyp.second, d);
	}

	return 0;
}