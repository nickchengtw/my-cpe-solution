#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		if (n==0) break;
	
		double tot=0;
		double allc[n];
		for(int i=0; i<n; i++)
		{
			double c;
			cin>>c;
			tot+=c;
			allc[i]=c;
		}
		double avg=tot/n;
		
		double dc_sum=0;
		for(int i=0; i<n; i++)
		{
			double dc=allc[i]-avg;
			//printf("%lf\n", dc);
			dc=((int)(dc*100))/100.0; 
			//printf("%lf\n", dc);
			
			dc_sum+=((dc>=0)? dc : -dc);
		}
		
		printf("$%0.2lf\n", dc_sum/2);
	}
}