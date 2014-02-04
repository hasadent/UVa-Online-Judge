/****
 * 10260 - Soundex
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int ascii[128];

int main()
{
    ascii['B'] = ascii['F'] = ascii['P'] = ascii['V'] = 1;
    ascii['C'] = ascii['G'] = ascii['J'] = ascii['K'] =
        ascii['Q'] = ascii['S'] = ascii['X'] = ascii['Z'] = 2;
    ascii['D'] = ascii['T'] = 3;
    ascii['L'] = 4;
    ascii['M'] = ascii['N'] = 5;
    ascii['R'] = 6;
    ascii['A'] = ascii['E'] = ascii['I'] = ascii['O'] =
        ascii['U'] = ascii['H'] = ascii['W'] = ascii['Y'] = -1;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char buf[50];
    while (gets(buf) != NULL)
    {
        vector<int> v;
        for (int i = 0; buf[i] != 0; i++)
            v.push_back(ascii[buf[i]]);

        vector<int>::iterator it = unique(v.begin(), v.end());
        v.resize(distance(v.begin(), it));

        for (int i : v)
        {
            if (i != -1)
                printf("%d", i);
        }
        puts("");

    }

    return 0;
}
