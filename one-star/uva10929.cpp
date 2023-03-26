#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool candiv(string n, int s)
{
	//cout<<n<<endl;
	if (n.size()-s<10) return ((stoi(string(n.begin()+s, n.end()))%11)==0);
	
	int d1 = n[s]-'0';
	int d2 = n[s+1]-'0';
	int d3 = n[s+2]-'0';
	int rem = (d1*100+d2*10+d3)%11;
	n[s+2]=rem%10+'0';
	rem/=10;
	n[s+1]=rem%10+'0';
	n[s]='0';
	int lz=1;
	for(int i=1; i<3; i++)
	{
		if (n[s+i]=='0') lz++;
		else break;
	}
	return candiv(n, s+lz);
}

int main()
{
	string n;
	while(cin>>n)
	{
		if (n=="0") break;
		
		bool div=candiv(n, 0);
		
		cout<<n;
		if (div) cout<<" is a multiple of 11."<<endl;
		else cout<<" is not a multiple of 11."<<endl;
	}

	return 0;
}