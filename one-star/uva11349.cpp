#include <iostream>
using namespace std;


bool is_sym(int s)
{
		int mat[s][s];
		
		for(int j=0; j<s; j++)
		{
			for(int k=0; k<s; k++)
			{
				int mij;
				cin >> mij;
				mat[j][k] = mij;
			}
		}
		
		for(int j=0; j<s; j++)
		{
			for(int k=0; k<s; k++)
			{
				if (s*s/2 < j*s+k+1) break;
				if (mat[j][k]<0) return false;
				//printf("%d %d\n", mat[j][k], mat[s-j-1][s-k-1]);
				if (mat[j][k] != mat[s-j-1][s-k-1]) return false;
			}
		}
		return true;
}

int main()
{
	int cnt;
	cin >> cnt;
	for (int i=0; i<cnt; i++)
	{
		char dum1, dum2;
		int s;
		cin >> dum1 >> dum2 >> s;
		//printf("%d\n", s);
		
		printf("Test #%d: %s\n", i+1, is_sym(s)?"Symmetric.":"Non-symmetric.");
	}
	
	return 0;
}