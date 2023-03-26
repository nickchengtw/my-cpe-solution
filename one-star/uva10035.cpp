#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	while(cin>>a>>b)
	{
		if (a==0&&b==0) break;
		
		int ca=0;
		int cc=0;
		while(a>0||b>0)
		{
			ca=((a%10)+(b%10)+ca)/10;
			if (ca) cc++;
			a/=10;
			b/=10;
		}
		
		if (cc) printf("%d carry operation%s.\n", cc, (cc>1)?"s":"");
		else printf("No carry operation.\n");
	}

	return 0;
}