#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

bool a_va(string a, string s)
{
	//cout<<a<<endl;
	int a_s=a.size();
	for(int i=0; i<s.size(); i++)
	{
		if (s[i] != a[i%a_s]) return false;
	}
	return true;
}

int main()
{
	string s;
	while(getline(cin, s))
	{
		if(s==".") break;
		
		int len;
		for(len=1; len<=s.size(); len++)
		{
			if (s.size()%len!=0) continue;
			
			string a=string(s.begin(), s.begin()+len);
			if (a_va(a, s)) break;
		}
		cout<<s.size()/len<<endl;
	}
}