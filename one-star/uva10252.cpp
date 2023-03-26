#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

string commPerm(string& a, string& b)
{
    unordered_map<char, int> charMap;
    char c;
    for (int i = 0; i < a.size(); i++)
    {
        c=a[i];
        if (charMap.find(c) == charMap.end()) charMap.insert(pair<char, int>(c, 0));
        charMap[c]++;
    }

    string comm;
    for (int i = 0; i < b.size(); i++)
    {
        c = b[i];
        if(charMap[c])
        {
            comm+=c;
            charMap[c]--;
        }
    }
    
    sort(comm.begin(), comm.end());
    return comm;
}
int main(int argc, char const *argv[])
{
    string a, b;
    while (cin >> a >> b)
    {
        cout<<commPerm(a, b)<<endl;
    }
    
    return 0;
}
