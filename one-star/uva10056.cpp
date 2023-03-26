#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
using namespace std;
//g++ .\oj.cpp; .\a.exe
int main(int argc, char const *argv[])
{
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        int players, ith;
        double p;
        cin >> players >> p >> ith;

        double winP = 0;
        for (int j = 0; j < 50; j++)
        {
            // printf("%f\n", winP);
            winP += pow(1-p, players*j + ith-1)*p;
        }
        
        printf("%0.4f\n", winP);
    }
    
    
    return 0;
}
