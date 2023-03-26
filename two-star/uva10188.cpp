#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

string getn(string s)
{
	string ns;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]>='0' && s[i]<='9') ns+=s[i];
	}
	return ns;
}

int main()
{
	int ans_c;
	for(int cc=1; cin>>ans_c; cc++)
	{
		cin.get();
		if (ans_c==0) break;
	
		vector<string> ans(ans_c);
		for(int i=0; i<ans_c; i++) getline(cin, ans[i]);
		
		int sol_c;
		cin>>sol_c;
		cin.get();
		vector<string> sol(sol_c);
		for(int i=0; i<sol_c; i++) getline(cin, sol[i]);
		
		//for(int i=0; i<ans_c; i++)
		//{
		//	cout<<ans[i]<<endl;
		//}
		
		string res="Accepted";
		if(ans_c!=sol_c) res="Wrong Answer";
		for(int i=0; i<ans_c; i++)
		{
			string ali=ans[i];
			string sli=sol[i];
			
			if(ali==sli) continue;
			else if(getn(ali)==getn(sli))
			{
				res="Presentation Error";
			}
			else
			{
				res="Wrong Answer";
				break;
			}
		}
		
		printf("Run #%d: ", cc);
		cout<<res<<endl;
	}
}