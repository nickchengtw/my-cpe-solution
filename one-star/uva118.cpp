#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int xlen, ylen;
vector<vector<int>> scent;

int cx, cy;
char cori;
int dx;
int dy;
bool lost=false;

void setori(char ori)
{
		switch(ori)
		{
			case 'N':
				dx=0;
				dy=1;
				break;
			case 'S':
				dx=0;
				dy=-1;
				break;
			case 'W':
				dx=-1;
				dy=0;
				break;
			case 'E':
				dx=1;
				dy=0;
				break;
		}
}

void tright()
{
	if(lost)return;
	char ori;
	switch(cori)
	{
		case 'N':
			ori='E';
			break;
		case 'E':
			ori='S';
			break;
		case 'S':
			ori='W';
			break;
		case 'W':
			ori='N';
			break;
	}
	setori(ori);
	cori=ori;
}

void tleft()
{
	if(lost)return;
	char ori;
	switch(cori)
	{
		case 'N':
			ori='W';
			break;
		case 'W':
			ori='S';
			break;
		case 'S':
			ori='E';
			break;
		case 'E':
			ori='N';
			break;
	}
	setori(ori);
	cori=ori;
}

void fow()
{
	if (lost)return;
	
	//printf("cur %d %d\n", cx, cy);
	int nx=cx+dx;
	int ny=cy+dy;
	//printf("n %d %d\n", nx, ny);
	if((nx<0 || nx>xlen || ny<0 || ny>ylen) )
	{
		if (!scent[cx][cy])
		{
			lost=true;
			scent[cx][cy]=1;
			return;
		}
		else return;
	}

	cx=nx;
	cy=ny;
}

int main()
{
	cin>>xlen>>ylen;
	scent=vector<vector<int>>(xlen+1, vector<int>(ylen+1, 0));
	
	string inst;
	while(cin>>cx>>cy>>cori)
	{
		cin.get();
		getline(cin, inst);
		
		setori(cori);
		lost=false;
		for(int i=0; i<inst.size(); i++)
		{
			char ci=inst[i];
			if(ci=='R') tright();
			else if(ci=='L') tleft();
			else if(ci=='F') fow();
		}
		
		printf("%d %d %c", cx, cy, cori);
		if(lost) cout<<" LOST";
		cout<<endl;
	}

	return 0;
}