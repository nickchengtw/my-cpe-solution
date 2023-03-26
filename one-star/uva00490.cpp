#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> strs;
    string s;
    int c;
    int maxLen = 0;
    while (getline(cin, s))
    {
        maxLen = max(maxLen, (int)s.size());
        strs.push_back(s);
    }
    for (int i = 0; i < maxLen; i++)
    {
        for (int j = strs.size()-1; j >= 0; j--)
        {
            if (i < strs[j].size()) printf("%c", strs[j][i]);
            else printf(" ");
        }
        printf("\n");
    }
    
    
    return 0;
}
