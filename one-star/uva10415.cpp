#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<int> cfin={2,3,4,7,8,9,10};
unordered_set<int> dfin={2,3,4,7,8,9};
unordered_set<int> efin={2,3,4,7,8};
unordered_set<int> ffin={2,3,4,7};
unordered_set<int> gfin={2,3,4};
unordered_set<int> afin={2,3};
unordered_set<int> bfin={2};
unordered_set<int> Cfin={3};
unordered_set<int> Dfin={1,2,3,4,7,8,9};
unordered_set<int> Efin={1,2,3,4,7,8};
unordered_set<int> Ffin={1,2,3,4,7};
unordered_set<int> Gfin={1,2,3,4};
unordered_set<int> Afin={1,2,3};
unordered_set<int> Bfin={1,2};
unordered_map<char, unordered_set<int>> finm;


int main()
{
	finm.insert(make_pair('c', cfin));
	finm.insert(make_pair('d', dfin));
	finm.insert(make_pair('e', efin));
	finm.insert(make_pair('f', ffin));
	finm.insert(make_pair('g', gfin));
	finm.insert(make_pair('a', afin));
	finm.insert(make_pair('b', bfin));
	finm.insert(make_pair('C', Cfin));
	finm.insert(make_pair('D', Dfin));
	finm.insert(make_pair('E', Efin));
	finm.insert(make_pair('F', Ffin));
	finm.insert(make_pair('G', Gfin));
	finm.insert(make_pair('A', Afin));
	finm.insert(make_pair('B', Bfin));
	
	int cnt;
	cin>>cnt;
	cin.get();
	for(int ctr=0; ctr<cnt; ctr++)
	{
		string song;
		getline(cin, song);
		
		int finc[11]={0};
		if(song.size())
		{
			char prev=song[0];
			unordered_set<int>::iterator it;
			for(it=finm[prev].begin(); it!=finm[prev].end(); it++)
			{
				finc[*it]++;
			}
			
			for(int i=1; i<song.size(); i++)
			{
				unordered_set<int> pf=finm[prev];
				unordered_set<int> cf=finm[song[i]];
				for(it=cf.begin(); it!=cf.end(); it++)
				{
					if (pf.find(*it)!=pf.end()) continue;
					//printf("%c %d\n", song[i], *it);
					finc[*it]++;
				}
				prev=song[i];
			}
		}
		
		printf("%d", finc[1]);
		for(int i=2; i<=10; i++)
		{
			printf(" %d", finc[i]);
		}
		cout<<endl;
	}

	return 0;
}