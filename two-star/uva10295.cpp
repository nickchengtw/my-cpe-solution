#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	int m, n;
	unordered_map<string, int> hpd;
	cin>>m>>n;
	for(int i=0; i<m; i++)
	{
		string w;
		int h;
		cin>>w>>h;
		hpd.insert(make_pair(w, h));
	}
	
	cin.get();
	for(int i=0; i<n; i++)
	{
		string des;
		getline(cin, des, '.');
		
		istringstream ss(des);
		int sal=0;
		string w;
		while(ss>>w)
		{
			if(hpd.find(w)!=hpd.end())
			{
				sal+=hpd[w];
			}
		}
		cout<<sal<<endl;
	}
}