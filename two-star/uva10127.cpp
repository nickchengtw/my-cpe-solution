#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int str_mod(string s, int m)
{
	cout<<s<<endl;
	if (s.size()<=6) return stoi(s)%m;
	
	string ss=string(s.begin(), s.begin()+6);
	string rem_d=to_string(stoi(ss)%m);
	string rem_str=string(s.begin()+6, s.end());
	return str_mod(rem_d+rem_str, m);
}

int main()
{
	int n;
	while(cin>>n)
	{
		int rem=0;
		for(int i=1; true; i++)
		{
			rem=(rem*10+1) % n;
			if (rem==0)
			{
				cout<<i<<endl;
				break;
			}
		}
	}

	return 0;
}