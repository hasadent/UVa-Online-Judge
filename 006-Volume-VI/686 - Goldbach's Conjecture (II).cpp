/****
 * 686 - Goldbach's Conjecture (II)
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

unsigned char prime[32767];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    memset(prime, 0, sizeof(prime));
    prime[0] = 1;
    prime[1] = 1;
    prime[2] = 0;
    for (int i = 2; i <= 32767; i++)
        if (prime[i] == 0)
            for (int j = i + i; j <= 32767; j += i)
                prime[j] = 1;

    int n;
    for (;;)
    {
        scanf("%d", &n);
        if (n == 0) break;

        if (n == 4)
        {
            puts("1");
            continue;
        }


        int c = 0;
        for (int i = 3; i <= n/2; i += 2)
        {
            if (prime[i] == 0 && prime[n - i] == 0)
                c++;
        }
        printf("%d\n", c);
    }

    return 0;
}
