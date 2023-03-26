#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> sns;
	for(int i=1; i*i<100000; i++)
	{
		sns.push_back(i*i);
	}

	int a, b;
	while(cin>>a>>b)
	{
		if (a==0&&b==0) break;
		
		int l = 0;
		int r = sns.size()-1;
		for (; sns[l]<a; l++);
		for (; sns[r]>b; r--);
		cout<< r-l+1 <<endl;
	}
}