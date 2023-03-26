#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s, t;
	while(cin>>s>>t)
	{
		int sp=0, tp=0;
		while(sp<s.size() && tp<t.size())
		{
			if (s[sp]==t[tp])
			{
				sp++;
				tp++;
			}
			else tp++;
		}
		bool subs = sp>=s.size();
		
		cout<<((subs)?"Yes":"No")<<endl;
	}

	return 0;
}