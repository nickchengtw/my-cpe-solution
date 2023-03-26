#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int ipow(int b, int n)
{
	if (n==0) return 1;
	return b*ipow(b, n-1);
}

bool isqn(int n, int l, int r)
{
	return (l+r)*(l+r) == n;
	//printf("%d %d\n", n, rdigi);
}

int main()
{
	int n;
	while(cin>>n)
	{
		//int max_n=ipow(10, n);
		int h=ipow(10, n/2);
		vector<int> qns={0, 1};
		for(int i=2; i<h; i+=2)
		{
			for(int j=0; j<h; j++)
			{
				if (isqn(i*h+j, i, j))qns.push_back(i*h+j);
			}
		}
		
		for(auto &&i:qns)
		{
			string s=to_string(i);
			string os=string(n-s.size(), '0')+s;
			cout<<os<<endl;
		}
	}

	return 0;
}