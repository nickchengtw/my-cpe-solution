#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> freq(65535, 0);
		vector<int> xs;
		for(int i=0; i<n; i++)
		{
			int x;
			cin>>x;
			xs.push_back(x);
			freq[x]++;
		}
		
		sort(xs.begin(), xs.end());
		
		int mp=(xs.size()%2==1)?(xs.size()/2):(xs.size()/2-1);
		int sat=(xs.size()%2==0&&xs[mp]!=xs[mp+1]) ? (freq[xs[mp]]+freq[xs[mp+1]]) : freq[xs[mp]];
		int pos=(xs.size()%2==0)? (xs[mp+1]-xs[mp]+1) : 1;
		printf("%d %d %d\n", xs[mp], sat, pos);
	}

	return 0;
}