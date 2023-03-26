#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

bool candiv(vector<int>& digi, int n)
{
	int n_1=n-1;
	
	int r=0;
	for(auto &&d: digi)
	{
		r=r*n+d;
		r=r%n_1;
	}
	return r==0;
}

int main()
{
	string s;
	while(getline(cin, s))
	{
		vector<int> digi;
		int lb=2;
		for(auto &&i:s)
		{
			int d;
			if (i>='0' && i<='9') d=i-'0';
			else if (i>='A' && i<='Z') d=i-'A'+10;
			else if (i>='a' && i<='z') d=i-'a'+36;
			else continue;
			digi.push_back(d);
			lb=max(lb, d+1);
		}
		
		bool divable=false;
		for(int i=lb; i<=62; i++)
		{
			if (candiv(digi, i))
			{
				cout<<i<<endl;
				divable=true;
				break;
			}
		}
		if(!divable) cout<<"such number is impossible!"<<endl;
	}

	return 0;
}