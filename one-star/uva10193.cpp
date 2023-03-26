#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;

int btoi(string s)
{
	int sum = 0;
	for(int i=s.size()-1; i>=0; i--)
	{
		sum += (s[s.size()-i-1]-'0')*(int)pow(2, i);
	}
	return sum;
}
int gcd(int a, int b)
{
	while(a%b)
	{
		int t=a%b;
		a = b;
		b = t;
	}
	return b;
}
int main()
{
	int cnt;
	cin>>cnt;
	for(int i=0; i<cnt; i++)
	{
		string s1, s2;
		cin>>s1>>s2;
		
		cout<<"Pair #"<<i+1<<": "<<((gcd(btoi(s1), btoi(s2))>1)?"All you need is love!":"Love is not all you need!")<<endl;
	}
}