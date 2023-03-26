#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int cnt;
	cin>>cnt;
	map<string, int> li;
	for(int ctr=0; ctr<cnt; ctr++)
	{
		string co;
		string wo;
		cin>>co;
		getline(cin, wo);
		
		if (li.find(co)==li.end()) li.insert(make_pair(co, 0));
		li[co]++;
	}

	map<string, int>::iterator it;
	for(it=li.begin(); it!=li.end(); it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}

	return 0;
}