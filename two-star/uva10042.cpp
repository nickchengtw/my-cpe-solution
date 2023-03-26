#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pvec={2};

void new_prime()
{
	for(int i=pvec.back()+1; true; i++)
	{
		bool pri=true;
		for(int j=0; pvec[j]*pvec[j]<=i; j++)
		{
			if(i % pvec[j] == 0)
			{
				pri=false;
				break;
			}
		}
		if (pri)
		{
			pvec.push_back(i);
			break;
		}
	}
}

int digisum(int n)
{
	if (n==0) return 0;
	return n%10 + digisum(n/10);
}

bool smi(int n)
{
	int ds=0;
	int n2=n;
	int i=0;
	while(pvec[i]*pvec[i]<=n2)
	{
		if(n2%pvec[i]==0)
		{
			ds+=digisum(pvec[i]);
			n2/=pvec[i];
			i=0;
		}
		else i++;
		
		if (i==pvec.size()) new_prime();
	}
	if (n2==n) return false;
	
	return ds+digisum(n2)==digisum(n);
}

int main()
{
	int cnt;
	cin>>cnt;
	for(int ctr=0; ctr<cnt; ctr++)
	{
		int n;
		cin>>n;
		for(; true; n++)
		{
			if(smi(n))
			{
				cout<<n<<endl;
				break;
			}
		}
	}

	return 0;
}