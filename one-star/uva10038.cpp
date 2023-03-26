#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;
//g++ .\oj.cpp; .\a.exe
int main(int argc, char const *argv[])
{
    int n;
    int ni;
    while (cin >> n)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> ni;
            v.push_back(ni);
        }
        
        unordered_set<int> set;
        int diff;
        int jol = true;
        for (int i = 1; i < n; i++)
        {
            diff = abs(v[i-1]-v[i]);
            if (diff > n-1)
            {
                jol = false;
                break;
            }
            if (set.find(diff) != set.end())
            {
                jol = false;
                break;
            }
            set.insert(diff);
        }
        
        cout << ((jol)?"Jolly":"Not jolly") << endl;
    }
    
    return 0;
}
