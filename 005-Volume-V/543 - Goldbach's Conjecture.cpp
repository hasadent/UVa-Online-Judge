/****
 * 543 - Goldbach's Conjecture
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

unsigned char prime[1000001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    prime[0] = 1;
    prime[1] = 0;
    prime[2] = 0;
    for (int i = 2; i <= 1000; i++)
        if (prime[i]==0)
            for (int j = i + i; j <= 1000000; j += i)
                prime[j] = 1;

    int n;
    for (;;)
    {
        scanf("%d", &n);
        if (n == 0) break;

        int i;
        int ub = n/2;
        for (i = 2; i <= ub; i++)
            if (prime[i] == 0 && prime[n-i] == 0)
            {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }

        if (i > ub)
            puts("Goldbach's conjecture is wrong.");

    }

    return 0;
}
