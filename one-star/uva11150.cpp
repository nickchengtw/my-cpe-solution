#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int drink(int c, int e, int b)
{
	if (c+e<b||c==0) return 0;
	return c+drink((c+e)/3, (c+e)%3, b);
}

int main()
{
	int n;
	while(cin>>n)
	{
		int opt=INT32_MIN;
		for(int i=0; i<200; i++)
		{
			opt=max(opt, drink(n, i, i));
		}
		cout<<opt<<endl;
	}

	return 0;
}