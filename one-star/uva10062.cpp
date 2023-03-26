#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmpless(pair<int, int>& a, pair<int, int>& b)
{
	return (a.second!=b.second) ? (a.second<b.second) : (a.first>b.first);
}

int main()
{
	string line;
	bool first=true;
	while(getline(cin, line))
	{
		if (!first) cout<<endl;
		first=false;
		
		unordered_map<int, int> freq;
		for(int i=0; i<line.size(); i++)
		{
			char c=line[i];
			if (freq.find(c)==freq.end()) freq.insert(make_pair(c, 0));
			freq[c]++;
		}
		vector<pair<int, int>> cfreq;
		unordered_map<int, int>::iterator it;
		for(it=freq.begin(); it!=freq.end(); it++)
		{
			cfreq.push_back(make_pair(it->first, it->second));
		}
		sort(cfreq.begin(), cfreq.end(), cmpless);
		
		for(int i=0; i<cfreq.size(); i++)
		{
			printf("%d %d\n", cfreq[i].first, cfreq[i].second);
		}
	}
	

	return 0;
}