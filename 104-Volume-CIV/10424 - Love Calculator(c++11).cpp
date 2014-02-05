/****
 * 10424 - Love Calculator
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int ascii[128] = {
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,
16,17,18,19,20,21,22,23,24,25,26, 0, 0, 0, 0, 0,
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,
16,17,18,19,20,21,22,23,24,25,26, 0, 0, 0, 0, 0,
};

int inline love_calc(const char * c)
{
    int sum = 0;
    for (; *c != 0; sum += ascii[*c], c++);
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char in1[28], in2[28];

    while (gets(in1) != NULL)
    {
        gets(in2);

        int s1 = love_calc(in1);
        int s2 = love_calc(in2);

        while (s1 >= 10)
        {
            int t = s1 % 10;
            s1 = s1 / 10 + t;
        }

        while (s2 >= 10)
        {
            int t = s2 % 10;
            s2 = s2 / 10 + t;
        }

        if (s2 == s1)
        {
            puts("100.00 %");
            continue;
        }

        if (s2 > s1)
        {
            int t = s1;
            s1 = s2;
            s2 = t;
        }

        double p = ((double)s2) / s1 * 100;
        printf("%.2f %\n", p);
    }

    return 0;
}
