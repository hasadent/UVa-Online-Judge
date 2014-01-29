/****
 * 369 - Combinations
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int y[101];

unsigned int c(int n, int r)
{
    /*if (r < n-r)
        return c(n, n-r);*/

    unsigned long long int x = 1;
    memset(y, 0, sizeof(y));

    for (int i = n, lb = 2, ub = n - r; i > r; )
    {
        for (; i > r && x < 166186883546932897L; i--)
            x *= i;

        for (int j = ub; j >= lb; j--)
        {
            if (y[j] == 0 && x % j == 0)
            {
                x /= j;
                y[j] = 1;
            }
        }

        while (y[lb] == 1) lb ++;
        while (y[ub] == 1) ub --;
    }

    return x;
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

        printf("%d things taken %d at a time is %u exactly.\n", a, b, c(a,b));
    }
    return 0;
}
