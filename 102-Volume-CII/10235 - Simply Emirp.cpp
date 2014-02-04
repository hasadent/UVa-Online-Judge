/****
 * 10235 - Simply Emirp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int PRIME_MAX = 1000001;

int prime[PRIME_MAX];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX; i++)
        if (prime[i] == 0)
            for (int j = i*2; j < PRIME_MAX; j += i)
                prime[j] = 1;

    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (prime[n] == 1)
        {
            printf("%d is not prime.\n", n);
            continue;
        }

        int rn = 0;
        for (int x = n; x != 0; rn = rn * 10 + x % 10, x /= 10);

        //printf("rn = %d\n", rn);
        if (rn == n || prime[rn] == 1)
            printf("%d is prime.\n", n);
        else
            printf("%d is emirp.\n", n);
    }

    return 0;
}
