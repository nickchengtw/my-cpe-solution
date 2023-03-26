#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

string muldig(string a, int d)
{
	//cout<<a<<" "<<d<<endl;
	string p(a.size(), '0');
	int ca=0;
	for(int i=a.size()-1; i>=0; i--)
	{
		int d2=a[i]-'0';
		p[i]=((d2*d+ca)%10) + '0';
		ca=(d2*d+ca)/10;
	}
	if (ca) p=((char)(ca+'0')) + p;
	
	return p;
}

string sumdig(string a, string b)
{
	if (b.size()>a.size())
	{
		string tmp=a;
		a=b;
		b=tmp;
	}
	
	string s(a.size(), '0');
	int i;
	int ca=0;
	for(i=1; i <= b.size(); i++)
	{
		int d1=a[a.size()-i]-'0';
		int d2=b[b.size()-i]-'0';
		s[s.size()-i]=((ca+d1+d2)%10) + '0';
		ca=(ca+d1+d2) / 10;
		
		//cout<<s<<endl;
	}
	
	for(; i <= a.size(); i++)
	{
		int d1=a[a.size()-i]-'0';
		s[s.size()-i]=((ca+d1)%10) + '0';
		ca=(ca+d1) / 10;
	}
	if (ca) s=(char)(ca+'0')+s;
	
	return s;
}

int main()
{
	string x, y;
	while(cin>>x>>y)
	{
		if (x=="0" || y=="0")
		{
			cout<<"0"<<endl;
			continue;
		}
		
		string prod;
		for(int i=x.size()-1; i>=0; i--)
		{
			int z=x.size()-i-1;
			string md= muldig(y, x[i]-'0');
			for(int zc=0; zc<z; zc++) md+='0';
			//cout<<md<<" "<<prod<<endl;
			prod=sumdig(prod, md);
		}
		
		cout<<prod<<endl;
	}

	return 0;
}