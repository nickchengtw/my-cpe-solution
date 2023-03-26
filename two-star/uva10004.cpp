#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool rec(int cur, vector<vector<int>>& adj, vector<int>& co, unordered_set<int>& vis, int cur_co)
{
	co[cur]= cur_co;
	vis.insert(cur);
	bool bic=true;
	for(int i=0; i<adj[cur].size(); i++)
	{
		int nv=adj[cur][i];
		//printf("%d %d\n", cur, nv);
		if (co[nv]==cur_co)
		{
			return false;
		}
		if (vis.find(nv)!=vis.end()) continue;
		bic=bic&&rec(nv, adj, co, vis, !cur_co);
	}
	return bic;
}

int main()
{
	int n, l;
	while(cin>>n>>l)
	{
		vector<vector<int>> adj(n);
		for(int j=0; j<l; j++)
		{
			int sv, ev;
			cin>>sv>>ev;
			adj[sv].push_back(ev);
			adj[ev].push_back(sv);
		}
		
		vector<int> co(n, -1);
		unordered_set<int> vis;
		bool bic=rec(0, adj, co, vis, 0);
		printf("%s\n", bic?"BICOLORABLE.":"NOT BICOLORABLE.");
	}

	return 0;
}