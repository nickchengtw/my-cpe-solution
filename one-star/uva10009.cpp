#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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
			
			string ap=to_ro(cits, sc[0]);
			string bp=to_ro(cits, ec[0]);
			ap=string(ap.rbegin(), ap.rend());
			bp=string(bp.rbegin(), bp.rend());
			
			char lv='R';
			int j;
			for(j=0; j<ap.size()&&j<bp.size(); j++)
			{
				if(ap[j]!=bp[j]) break;
				lv=ap[j];
			}
			ap=string(ap.begin()+j, ap.end());
			string mp=string(ap.rbegin(), ap.rend())+lv+string(bp.begin()+j, bp.end());
			
			cout<<mp<<endl;
		}
	}

	return 0;
}