#include <iostream>
using namespace std;

int main()
{
	int cnt;
	cin>>cnt;
	for(int i=0; i<cnt; i++)
	{
		int a, b;
		cin >> a >> b;
		int sum=0;
		if (a%2==0) a++;
		for(int j=a; j<= b; j+=2)
		{
			sum+=j;
		}
		cout<<"Case "<<i+1<<": "<<sum<<endl;
	}
}