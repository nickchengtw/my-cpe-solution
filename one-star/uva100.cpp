#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int cl(int n, unordered_map<unsigned int, int>& dp)
{
	//printf("cur %d\n", n);
	if (dp.find(n)!=dp.end()) return dp[n];
	int ncl=(n%2)?cl(3*n+1, dp):cl(n/2, dp);
	ncl++;
	dp.insert(make_pair(n,ncl));
	return ncl;
}

int main()
{
	int a, b;
	while(cin>>a>>b)
	{
		unordered_map<unsigned int, int> dp;
		dp.insert(make_pair(1, 1));
		
		int mcl=INT32_MIN;
		for(int i=min(a, b); i<=max(a, b); i++)
		{
			mcl=max(mcl, cl(i, dp));
			//cout<<"end"<<endl;
		}
		
		printf("%d %d %d\n", a, b, mcl);
	}

	return 0;
}