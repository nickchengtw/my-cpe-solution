#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int bctn(int n)
{
    return n ? (n&1) + bctn(n>>1) : 0;
}
int main(int argc, char const *argv[])
{
    int ic;
    scanf("%d", &ic);

    int n;
    for (int i = 0; i < ic; i++)
    {
        scanf("%d", &n);
        
        int n2 = n;
        int x2 = 0;
        for (int i = 0; n2 > 0; i++)
        {
            int fd=n2%10;

            int h2 = fd*16;
            x2+=bctn(h2);
            n2/=10;
        }
        
        printf("%d %d\n", bctn(n), x2);
    }
    
    
    return 0;
}
