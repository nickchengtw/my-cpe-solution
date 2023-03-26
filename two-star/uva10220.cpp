#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

const int BNS=10000;
void mul(int a[], int b)
{
	for(int i=0; i<BNS; i++)
	{
		a[i]*=b;
	}
	int ca=0;
	for(int i=0; i<BNS; i++)
	{
		int tmp=a[i];
		a[i]=(a[i]+ca)%10;
		ca=(tmp+ca)/10;
	}
	
	//for(int i=BNS-1; i>=0; i--)
	//{
	//	cout<<a[i];
	//}
	//cout<<endl;
}

int dsum(int n)
{
	int fac[BNS]={0};
	fac[0]=1;
	for(int i=2; i<=n; i++)
	{
		mul(fac, i);
	}
	
	int sum=0;
	for(int i=0; i<BNS; i++)
	{
		sum+=fac[i];
	}
	return sum;
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<dsum(n)<<endl;
	}

	return 0;
}