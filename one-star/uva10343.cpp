#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int cton(char c)
{
	if (c>='0'&&c<='9') return c-'0'+52;
	else if (c>='a'&&c<='z') return c-'a'+26;
	else if (c>='A'&&c<='Z') return c-'A';
	else return 0;
}

string dec(string s)
{
	if (s=="") return "";

	int bg=0;
	bg=cton(s[0]);
	bg=(bg<<6)+cton(s[1]);
	bg=(bg<<6)+cton(s[2]);
	bg=(bg<<6)+cton(s[3]);
	//cout<<bg<<endl;
	
	if (s[2]=='=') bg>>=16;
	else if (s[3]=='=') bg>>=8;
	
	string ch;
	if(bg&0xFF0000) ch+=(bg&0xFF0000)>>16;
	if(bg&0xFF00) ch+=(bg&0xFF00)>>8;
	ch+=bg&0xFF;
	
	//cout<<ch<<endl;
	return ch+dec(string(s.begin()+4, s.end()));
}

int main()
{
	bool ctr=0;
	while(true)
	{
		string s;
		getline(cin, s, '#');
		
		istringstream ss(s);
		string data;
		while(ss>>s)
		{
			data+=s;
		}
		if (data=="") break;
		
		cout<<dec(data)<<"#";
	}

	return 0;
}
