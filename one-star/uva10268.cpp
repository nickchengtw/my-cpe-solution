#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int x;
	while(cin>>x)
	{
		cin.get();
		
		vector<int> coef;
		int a;
		while(cin>>a)
		{
			coef.push_back(a);
			if (cin.get() == '\n') break;
		}
		
		int sum=0;
		for(int i=coef.size()-1; i>=1; i--)
		{
			//cout<<i<<" "<<coef[coef.size()-i-1]<<endl;
			sum += coef[coef.size()-i-1] * i * pow(x, i-1);
		}
		
		cout<<sum<<endl;
	}
}