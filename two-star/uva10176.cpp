#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

const int N=131071;
bool divable(string ds)
{
	int r=0;
	for(int i=0; i<ds.size(); i++)
	{
		int d=ds[i]-'0';
		
		r=(r*10+d);
		r%=N;
		//cout<<r<<endl;
	}
	return r==0;
}

int main()
{
	string s;
	while(getline(cin, s, '#'))
	{
		istringstream iss(s);
		string digi;
		while(iss>>s) digi+=s;
		if (digi=="") continue;
		
		cout<<(divable(digi)?"YES":"NO")<<endl;
	}

	return 0;
}