#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
//g++ .\oj.cpp; .\a.exe
int main(int argc, char const *argv[])
{
    int ctr;
    cin >> ctr;
    int mon, day;
    for (int i = 0; i < ctr; i++)
    {
        cin >> mon >> day;

        int ddd;
        switch (mon)
        {
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
            ddd = mon;
            break;
        case 5:
            ddd = 9;
            break;
        case 9:
            ddd = 5;
            break;
        case 7:
            ddd = 11;
            break;
        case 11:
            ddd = 7;
            break;
        case 1:
            ddd = 10;
            break;
        case 2:
            ddd = 21;
            break;
        case 3:
            ddd = 7;
            break;
        default:
            break;
        }

        int mondayOffset = (day>=ddd) ? (day-ddd)%7 : (7-((ddd-day)%7))%7;
        string t;
        switch (mondayOffset)
        {
        case 0:
            t="Monday";
            break;
        case 1:
            t="Tuesday";
            break;
        case 2:
            t="Wednesday";
            break;
        case 3:
            t="Thursday";
            break;
        case 4:
            t="Friday";
            break;
        case 5:
            t="Saturday";
            break;
        case 6:
            t="Sunday";
            break;
        default:
            break;
        }
        cout << t << endl;
    }
    
    
    return 0;
}
