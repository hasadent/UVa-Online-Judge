/****
 * 10302 - Summation of Polynomials
 *
 *  Reference:
 *   http://polysum.tripod.com/
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    unsigned int n;
    while (scanf("%u", &n) != EOF)
    {
        if (n < 256)
        {
            printf("%u\n", n * n * (n+1) * (n+1) / 4);
        }
        else
        {
            long long int x = n*n;
            x *= (n+1)*(n+1);
            x /= 4;
            printf("%lld\n", x);
        }
    }

    return 0;
}
