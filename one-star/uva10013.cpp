#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string n1;
string n2;

int main()
{
	int cnt;
	cin>>cnt;
	for(int ctr=0; ctr<cnt; ctr++)
	{
		if (ctr) cout<<endl;
		
		int s;
		scanf("%d\n", &s);
		n1="";
		n2="";
		for(int i=0; i<s; i++)
		{
			char d1, d2;
			scanf("%c %c\n", &d1, &d2);
			//cout<<d1<<" "<<d2<<endl;
			n1+=d1;
			n2+=d2;
		}
		
		int ca=0;
		for(int i=s-1; i>=0; i--)
		{
			int d1=n1[i]-'0';
			int d2=n2[i]-'0';
			n1[i]=((d1+d2+ca)%10)+'0';
			ca=(d1+d2+ca)/10;
		}
		if (ca) n1='1'+n1;
		cout<<n1<<endl;
	}

	return 0;
}