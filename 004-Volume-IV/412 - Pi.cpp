/****
 * 412 - Pi
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int v[51];

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);

        int s = n * (n - 1) / 2;
        int c = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (gcd(v[i], v[j]) == 1)
                    c += 1;

        if (c != 0)
        {
            double pi = sqrt(6.0 * s / c);
            printf("%.6lf\n", pi);
        }
        else
            puts("No estimate for this data set.");
    }
    return 0;
}
