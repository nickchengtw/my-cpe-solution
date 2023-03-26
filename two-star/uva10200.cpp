#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(int n)
{
	if (n<=3) return true;
	if (n%2==0 || n%3==0) return false;
	for(int i=5; i*i<=n; i+=6)
	{
		if (n%i==0 || n%(i+2)==0) return false;
	}
	return true;
}

int f(int n)
{
	return n*n+n+41;
}

int main()
{
	vector<int> fn_ptn(10001);
	int ptn=0;
	int uplim=f(10000);
	for(int i=0; f(i)<=uplim; i++)
	{
		if (is_prime(f(i)))
		{
			ptn++;
		}
		fn_ptn[i]=ptn;
	}

	int a, b;
	while(cin>>a>>b)
	{
		int pts=fn_ptn[a];
		int pte=fn_ptn[b];
		//printf("%d %d\n", pts, pte);
		int pc=pte-pts;
		pc+=is_prime(f(a));
		double ab_s=b-a+1;
		
		printf("%0.2lf\n", pc/ab_s*100);
	}
}