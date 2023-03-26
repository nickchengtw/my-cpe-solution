#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool val(vector<vector<char>>& rec, int m, int n, int r, int c, int s)
{
	char ch = rec[r][c];
	int rst=r-s;
	int cst=c-s;
	int rend=r+s;
	int cend=c+s;
	if (rst<0||rend>=m||cst<0||cend>=n) return false;
	
	for(int i=rst; i<=rend; i++)
	{
		for(int j=cst; j<=cend; j++)
		{
			if(rec[i][j] != ch) return false;
		}
	}
	return true;
}

int main()
{
	int cnt;
	cin>>cnt;
	for(int c; c<cnt; c++)
	{
		int m, n, q;
		cin>>m>>n>>q;
		vector<vector<char>> rec(m, vector<char>(n));
		for(int i=0; i<m; i++)
		{
			string line;
			cin>>line;
			for(int j=0; j<n; j++)
			{
				rec[i][j] = line[j];
			}
		}
		
		vector<pair<int, int>> rcs;
		for(int i=0; i<q; i++)
		{
			int r, c;
			cin>>r>>c;
			rcs.push_back(make_pair(r, c));
		}
		printf("%d %d %d\n", m, n, q);
		
		for(int i=0; i<q; i++)
		{
			pair<int, int> rc = rcs[i];
			int r=rc.first;
			int c=rc.second;
			if (r<0||r>=m||c<0||c>=n)
			{
				cout<<'1'<<endl;
				continue;
			}
			
			int lrec = 1;
			int s=1;
			for(; val(rec, m, n, r, c, s); s++)
			{
				lrec=max(lrec, 2*s+1);
			}
			
			cout<<lrec<<endl;
		}
	}

	return 0;
}