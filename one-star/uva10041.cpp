#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int cnt;
	cin>>cnt;
	for(int ctr=0; ctr<cnt; ctr++)
	{
		int s;
		cin>>s;
		vector<int> hs(s);
		for(int i=0; i<s; i++)
		{
			cin>>hs[i];
		}
		sort(hs.begin(), hs.end());
		
		int mid=hs[s/2];
		int dist=0;
		for(int i=0; i<s; i++)
		{
			dist+=abs(hs[i]-mid);
		}
		
		cout<<dist<<endl;
	}

	return 0;
}