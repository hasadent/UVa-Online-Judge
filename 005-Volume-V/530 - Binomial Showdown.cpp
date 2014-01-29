/****
 * 530 - Binomial Showdown
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

unsigned int c(int n, int r)
{
    if (r < n-r)
        return c(n, n-r);

    unsigned long long int x = 1, y = 1;

    int i, j;
    for (i = n, j = n - r; j > 0; )
    {
        for (; i > r && x < 166186883546932897L; i--)
            x *= i;

        if (x % y == 0)
        {
            x /= y;
            y = 1;
        }

        int retry = 0;
        for (; j > 0 && retry < 1; j--)
            if (x % j == 0)
                x /= j;
            else
            {
                y *= j;
                retry += 1;
            }
    }

    for (; i > r; i--)
        x *= i;

    return x / y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, b;
    for (;;)
    {
        scanf("%d %d", &a, &b);

        if (a == 0) break;

        printf("%d\n", c(a,b));
    }
    return 0;
}
