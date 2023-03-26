#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		if (n==0) break;
		
		unordered_map<long long, int> popu;
		vector<long long> cs(5);
		int max_pop=0;
		while(n--)
		{
			cin>>cs[0]>>cs[1]>>cs[2]>>cs[3]>>cs[4];
			sort(cs.begin(), cs.end());
			long long ke=cs[0]*1000000000000+cs[1]*1000000000+cs[2]*1000000+cs[3]*1000+cs[4];
			//cout<<ke<<endl;
			
			if(popu.find(ke)==popu.end()) popu.insert(make_pair(ke, 0));
			popu[ke]++;
			max_pop=max(max_pop, popu[ke]);
		}
		
		int sel_pop=0;
		auto it=popu.begin();
		for(; it!=popu.end(); it++)
		{
			if (it->second==max_pop) sel_pop+=it->second;
		}
		
		cout<<sel_pop<<endl;
	}

	return 0;
}