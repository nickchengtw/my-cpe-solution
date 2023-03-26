#include <iostream>
#include <string>
using namespace std;

int ndeg(int n)
{
	if (n==9) return 1;
	int dsum = 0;
	string ns = to_string(n);
	for(int i=0; i<ns.size(); i++)
	{
		dsum += ns[i]-'0';
	}
	//printf("%d %d\n", n, dsum);
	return 1+ndeg(dsum);
}

int main()
{
	string n;
	while(cin>>n)
	{
		if (n=="0") break;
		
		int dsum=0;
		for(int i=0; i<n.size(); i++)
		{
			dsum += n[i]-'0';
		}
		if (dsum%9) {cout<<n; printf(" is not a multiple of 9.\n", n);}
		else {cout<<n;printf(" is a multiple of 9 and has 9-degree %d.\n", ndeg(dsum));}
	}

	return 0;
}