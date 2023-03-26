#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

bool is_pri(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	int n;
	while(cin>>n)
	{
		string sn = to_string(n);
		int rn = stoi(string(sn.rbegin(), sn.rend()));
		if (n!=rn && is_pri(n) && is_pri(rn))
		{
			printf("%d is emirp.\n", n);
		}
		else if (is_pri(n)) printf("%d is prime.\n", n);
		else printf("%d is not prime.\n", n);
	}
}