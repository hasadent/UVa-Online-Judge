/****
 * 11332 - Summing Digits
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    for (;;)
    {
        scanf("%d\n", &n);
        if (n == 0) break;

        int r = 10;
        for (;r >= 10;)
        {
            r = 0;
            for (; n > 0; r += n % 10, n /= 10);
            n = r;
        }

        printf("%d\n", r);
    }

    return 0;
}
