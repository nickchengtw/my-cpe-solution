#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	while(cin>>n>>m)
	{
		if(n%m) cout<<"Boring!"<<endl;
		else
		{
			vector<int> seq = {n};
			bool bor=false;
			while(n>1)
			{
				if(n%m)
				{
					bor=true;
					break;
				}
				seq.push_back(n/m);
				n=n/m;
				if(seq[seq.size()-2]<=seq[seq.size()-1])
				{
					bor=true;
					break;
				}
			}
			if(bor || seq.size() < 2) cout<<"Boring!"<<endl;
			else
			{
				cout<<seq[0];
				for(int i=1; i<seq.size(); i++)
				{
					printf(" %d", seq[i]);
				}
				cout<<endl;
			}
		}
	}
}