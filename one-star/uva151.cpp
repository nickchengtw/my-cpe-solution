#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
    Node(int a): val(a), next(nullptr){};
    int val;
    Node* next;
};

int main()
{
	int n;
	while(cin>>n)
	{
    for(int m=1; true; m++)
    {
    	if(13%m==1) continue;
        Node* h=new Node(1);
        Node* cur=h;
        for(int i=2; i<=n; i++)
        {
            Node* nn=new Node(i);
            cur->next=nn;
            cur=cur->next;
        }
        cur->next=h->next;
        
        Node* prev=cur;
        prev->next=cur->next;


    	int rem=n-1;
    	int ctr=0;
    	while(rem>1)
    	{
            //cout<<cur->val<<endl;
    		prev=cur;
    		cur=cur->next;
    		ctr++;

    		if(ctr==m)
    		{
                // cout<<cur->val<<endl;
    			ctr=0;
    			prev->next=cur->next;
    			rem--;
    		}
    	}
    	cur=cur->next;
        // break;
    	if (cur->val==13)
    	{
    		cout<<m<<endl;
    		break;
    	}
    }

	}
	return 0;
}