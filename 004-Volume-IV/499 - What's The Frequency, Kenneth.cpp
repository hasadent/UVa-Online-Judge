/****
 * 499 - What's The Frequency, Kenneth
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char buf[1024];
    int chmap[128];

    while (gets(buf) != NULL)
    {
        if (buf[0] == 0) break;

        memset(chmap+64, 0, 64*sizeof(int));

        for (int i = 0; buf[i] != 0; i++)
            chmap[buf[i]] += 1;

        int max = 0;
        for (int i = 65; i < 128; i++)
            if (chmap[i] > max) max = chmap[i];

        for (int i = 65; i < 128; i++)
            if (chmap[i] == max) putchar(i);

        printf(" %d\n", max);
    }

    return 0;
}
