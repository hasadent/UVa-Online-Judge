/****
 * 583 - Prime Factors
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int PRIME_MAX = 50000;
int prime[PRIME_MAX];

const char * fmt;
const char * fmt0 = "%d";
const char * fmt1 = " x %d";

int main()
{
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;

    for (int i = 2; i < PRIME_MAX; i++)
      if (prime[i] == 0)
         for (int j = i*2; j < PRIME_MAX; j += i)
           prime[j] = 1;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    for (;;)
    {
        scanf("%d\n", &n);
        if (n == 0) break;

        printf("%d = ", n);
        fmt = fmt0;

        if (n == 1)
        {
            puts("1");
            continue;
        }

        if (n == -1)
        {
            puts("-1");
            continue;
        }

        if (n <= 0)
        {
            printf("-1");
            fmt = fmt1;
            n = -n;
        }

        while(n % 2 == 0)
        {
            printf(fmt, 2);
            fmt = fmt1;
            n /= 2;
        }

        for (int i = 3; i < PRIME_MAX && n != 1 && n >= i; i+=2)
            if (prime[i] == 0)
            {
                while(n % i == 0)
                {
                    printf(fmt, i);
                    fmt = fmt1;
                    n /= i;
                }
            }

        if (n != 1)
        {
            printf(fmt, n);
        }

        puts("");
    }

    return 0;
}
