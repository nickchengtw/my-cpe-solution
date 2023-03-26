#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	double a, b;
	while(cin>>a>>b)
	{
		printf("%.0lf\n", max(a, b)-min(a, b));
	}

	return 0;
}