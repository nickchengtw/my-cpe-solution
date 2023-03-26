#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ver, hor;

void rolln()
{
	rotate(ver.begin(), ver.begin()+3, ver.end());
	hor[1]=ver[1];
	hor[3]=ver[3];
}

void rolls()
{
	rotate(ver.begin(), ver.begin()+1, ver.end());
	hor[1]=ver[1];
	hor[3]=ver[3];
}

void rollw()
{
	rotate(hor.begin(), hor.begin()+1, hor.end());
	ver[1]=hor[1];
	ver[3]=hor[3];
}

void rolle()
{
	rotate(hor.begin(), hor.begin()+3, hor.end());
	ver[1]=hor[1];
	ver[3]=hor[3];
}

int main()
{
	int cnt;
	while(cin>>cnt)
	{
		if (cnt==0) break;
		
		ver={5, 1, 2, 6};
		hor={3, 1, 4, 6};
		for(int i=0; i<cnt; i++)
		{
			string ac;
			cin>>ac;
			switch(ac[0])
			{
				case 'n':
					rolln();
					break;
				case 's':
					rolls();
					break;
				case 'w':
					rollw();
					break;
				case 'e':
					rolle();
					break;
			}
		}
		
		cout<<ver[1]<<endl;
	}

	return 0;
}