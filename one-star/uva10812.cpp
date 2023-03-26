#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int cnt;
	cin >> cnt;
	for(int i=0; i<cnt; i++)
	{
		int s, d;
		cin >> s >> d;
		
		int a, b;
		a = (a*2>s)? a=(s+d)/2 : a=(s-d)/2;
		b = s-a;
		if (a<0 || b<0 || abs(s-d)%2==1)
		{
			cout << "impossible"<<endl;
		} else
		cout << max(a, b) << " " << min(a, b) << endl;
	}
}