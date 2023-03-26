#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

int bcost(int cost[36], int base, int y)
{
	int s = 0;
	while(y)
	{
		s += cost[y%base];
		y/=base;
	}
	return s;
}

vector<int> cb(int cost[36], int y)
{
	int cheap = INT32_MAX;
	vector<int> cbs;
	for (int i=2; i<=36; i++)
	{
		int bc = bcost(cost, i, y);
		//cout << bc << " "<<i<<endl;
		if (bc<cheap)
		{
			cbs = {i};
			cheap = bc;
		}
		else if (bc==cheap) cbs.push_back(i);
	}
	return cbs;
}

int main()
{
	int cnt;
	cin>>cnt;

	for(int i=0; i<cnt; i++)
	{
		printf("Case %d:\n", i+1);
		int c;
		int cost[36];
		for(int j=0; j<36; j++)
		{
			cin >> c;
			cost[j] = c;
		}
		
		int cnt2;
		cin >> cnt2;
		for (int j=0; j<cnt2; j++)
		{
			int y;
			cin >> y;
			vector<int> cbs = cb(cost, y);
			printf("Cheapest base(s) for number %d: %d", y, cbs[0]);
			for(int i=1;i<cbs.size();i++) printf(" %d", cbs[i]);
			cout<<endl;
		}
		if(i<cnt-1)cout<<endl;
	}
	
	return 0;
}