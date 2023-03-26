#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int cnt;
	cin>>cnt;
	for(int ctr=0; ctr<cnt; ctr++)
	{
		int sx, sy, ex, ey;
		cin>>sx>>sy>>ex>>ey;
		
		int ln=ex+ey;
		int lns=0;
		for(int i=sx+sy+1; i<=ln; i++)
		{
			lns+=i;
		}
		
		int sc=lns+ex-sx;
		
		printf("Case %d: %d\n", ctr+1, sc);
	}

	return 0;
}