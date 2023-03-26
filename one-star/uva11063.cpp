#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool b2(int len)
{
		int bs[len];
		for(int i=0; i<len; i++)
		{
			int b;
			cin>>b;
			bs[i] = b;
		}
		
		unordered_set<int> sums;
		for(int i=0; i<len; i++)
		{
			for(int j=i; j<len; j++)
			{
				if (bs[i]<1 || bs[j]<1) return false;
				if (i!=j && bs[i]>=bs[j])return false;
				int s = bs[i]+bs[j];
				//printf("%d %d\n", i, j);
				if (sums.find(s) != sums.end()) return false;
				sums.insert(s);
			}
		}
		return true;
}
int main()
{
	int len;
	int cnt = 0;
	while(cin>>len)
	{
		printf("Case #%d: %s\n\n", ++cnt, (b2(len))?"It is a B2-Sequence.":"It is not a B2-Sequence.");
	}
}