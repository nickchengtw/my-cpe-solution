#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int cnt;
	cin>>cnt;
	for(int ctr=0; ctr<cnt; ctr++)
	{
		int len;
		cin>>len;
		int ns[len];
		for(int i=0; i<len; i++)
		{
			cin>>ns[i];
		}
	
		int sw=0;
		for(int i=len-1; i>=1; i--)
		{
			for(int j=0; j<i; j++)
			{
				if (ns[j]>ns[j+1])
				{
					int tmp=ns[j];
					ns[j]=ns[j+1];
					ns[j+1]=tmp;
					
					sw++;
				}
			}
			//for(int i=0; i<len; i++) cout<<ns[i]<<" ";
		}
		printf("Optimal train swapping takes %d swaps.\n", sw);
	}
}