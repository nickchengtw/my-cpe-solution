#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool have_mine(vector<vector<char>>& mines, int r, int c)
{
	if (r<0 || r>=mines.size() || c<0 || c>=mines[0].size()) return false;
	return mines[r][c]=='*';
}

int main()
{
	int m, n;
	int ctr=1;
	while(cin>>m>>n)
	{
		if (m==0&&n==0) break;
		if (ctr>1) cout<<endl;
		cin.get();
		vector<vector<char>> mines(m, vector<char>(n, ' '));
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				mines[i][j]=cin.get();
			}
			cin.get();
		}
		
		printf("Field #%d:\n", ctr++);
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if (mines[i][j]=='*')
				{
					cout<<'*';
					continue;
				}
				int mc=0;
				mc+=have_mine(mines, i-1, j-1);
				mc+=have_mine(mines, i-1, j);
				mc+=have_mine(mines, i-1, j+1);
				mc+=have_mine(mines, i, j-1);
				mc+=have_mine(mines, i, j+1);
				mc+=have_mine(mines, i+1, j-1);
				mc+=have_mine(mines, i+1, j);
				mc+=have_mine(mines, i+1, j+1);
				cout<<mc;
			}
			cout<<endl;
		}
	}

	return 0;
}