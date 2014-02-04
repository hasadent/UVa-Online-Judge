/****
 * 10006 - Carmichael Numbers
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int PRIME_MAX = 65000;
const int PRIME_MAX_SQRT = 256;
int prime[PRIME_MAX];

unsigned int mod(unsigned int b, unsigned int p, unsigned int m)
{
    if (p == 0)
        return 1;

    if (p == 1)
        return b % m;

    if ((p&1) == 0)
        return mod((b*b)%m, p/2, m);

    return (b * mod((b*b)%m, p/2, m)) % m;
}

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
    for (;;)
    {
        scanf("%d", &n);
        if (n == 0) break;

        if (prime[n] == 0)
        {
            printf("%d is normal.\n", n);
            continue;
        }

        bool is_normal = false;
        for (int i = 2; i < n; i++)
            if (mod(i, n, n) != i)
            {
                is_normal = true;
                break;
            }

        if (is_normal)
            printf("%d is normal.\n", n);
        else
            printf("The number %d is a Carmichael number.\n", n);
    }

    return 0;
}
