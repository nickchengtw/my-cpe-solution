#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

string to_ro(vector<vector<char>>& cits, char cc)
{
	if (cc=='R') return "R";
	//printf("%c %c\n", cc, cits[cc-'A'][0]);
	return cc+to_ro(cits, cits[cc-'A'][0]);
}


int main()
{
	int cnt;
	cin>>cnt;
	for(int ctr=0; ctr<cnt; ctr++)
	{
		int cn, qn;
		cin>>cn>>qn;
		vector<vector<char>> cits(26);
		for(int i=0; i<cn; i++)
		{
			string sc, ec;
			cin>>sc>>ec;
			cits[ec[0]-'A'].push_back(sc[0]);
		}
		
		//for(int i=0; i<26; i++)
		//{
		//	printf("%c\n", cits[i].size());
		//}
		
		for(int i=0; i<qn; i++)
		{
			string sc, ec;
			cin>>sc>>ec;
			
			unordered_map<char, string> ps;
			string cp;
			char cc=ec[0];
			ps.insert(make_pair(cc, cp));
			cp=cc+cp;
			while(cc!='R')
			{
				cc=cits[cc-'A'][0];
				ps.insert(make_pair(cc, cp));
				cp=cc+cp;
			}
			
			string mp;
			cc=sc[0];
			while(true)
			{
				mp+=cc;
				if(ps.find(cc)!=ps.end()) break;
				cc=cits[cc-'A'][0];
			}
			mp+=ps[cc];
			
			cout<<mp<<endl;
		}
	}

	return 0;
}