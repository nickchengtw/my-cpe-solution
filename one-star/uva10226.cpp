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
	cin.get();
	cin.get();
	for(int ctr=0; ctr<cnt; ctr++)
	{
		if(ctr) cout<<endl;
		
		unordered_map<string, int> tre;
		string inp;
		int total=0;
		while(getline(cin, inp))
		{
			//cout<<"inp "<<inp<<endl;;
			if (!inp.size())break;
			if (tre.find(inp)==tre.end()) tre.insert(make_pair(inp, 0));
			tre[inp]++;
			total++;
		}
		//cout<<"start"<<endl;
		
		vector<pair<string, int>> stree;
		unordered_map<string, int>::iterator it;
		for(it=tre.begin(); it!=tre.end(); it++)
		{
			stree.push_back(make_pair(it->first, it->second));
		}
		sort(stree.begin(), stree.end());
		
		for(int i=0; i<stree.size(); i++)
		{
			cout<<stree[i].first;
			printf(" %0.4lf\n", stree[i].second/(double)total*100);
		}
	}

	return 0;
}