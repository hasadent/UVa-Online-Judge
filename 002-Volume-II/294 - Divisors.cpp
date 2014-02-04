/****
 * 294 - Divisors
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int PRIME_MAX = 1500; /* 32000 */
const int PRIME_MAX_SQRT = 40;
int prime[PRIME_MAX];

int main()
{
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;

    for (int i = 2; i < PRIME_MAX_SQRT; i++)
      if (prime[i] == 0)
         for (int j = i*2; j < PRIME_MAX; j += i)
           prime[j] = 1;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    int l, u, d, p;

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d %d", &l, &u);

        d = 0, p = 0;
        for (int i = l; i <= u; i++)
        {
            int s = 1;
            int c = i;
            int q;

            for (q = 1; c % 2 == 0; q += 1, c /= 2);
            s *= q;

            for (int j = 3; j < PRIME_MAX && c > j ; j+=2)
            {
                if (prime[j] == 0)
                {
                    for (q = 1; c % j == 0; q += 1, c /= j);
                    s *= q;
                }
            }

            if (c != 1)
                s *= 2;

            if (s > d)
            {
                p = i;
                d = s;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, p, d);
    }

    return 0;
}
