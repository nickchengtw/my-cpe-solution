#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main()
{
	int cnt;
	cin>>cnt;
	int n, p;
	for(int icnt=0; icnt<cnt; icnt++)
	{
		cin>>n>>p;
		int hs[p];
		for(int i=0; i<p; i++)
		{
			int h;
			cin >> h;
			hs[i]=h;
		}
		
		int los = 0;
		unordered_set<int> hed;
		for(int i=0; i<p; i++)
		{
			int lh = 0;
			lh+=hs[i];
			while(lh<=n)
			{
				//printf("%d %d\n", hs[i], lh);
				if(lh%7!=0 && lh%7-6!=0 && hed.find(lh)==hed.end())
				{
					los++;
					hed.insert(lh);
				}
				lh+=hs[i];
			}
		}
		cout<<los<<endl;
	}
}