/****
 * 10940 - Throwing Cards Away II
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int r[500002];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    r[1] = 1;

    for (int i = 2; i <= 500000; i+=4)
    {
        int h = i / 2;
        r[i]   = r[h] * 2;
        r[i+1] = (r[h+1] - 1) * 2;
        r[i+2] = r[h+1] * 2;
        r[i+3] = (r[h+2] - 1) * 2;
    }

    int n;
    for (;;)
    {
        scanf("%d", &n);

        if (n == 0)
            break;

        printf("%d\n", r[n]);
    }
    return 0;
}
