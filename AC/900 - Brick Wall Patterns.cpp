/****
 * 900 - Brick Wall Patterns
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long int p[51];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    p[0] = 1;
    p[1] = 1;

    // p[i]  =
    //
    //     p[i-1]  +   |  (1 brick)
    //
    //     pi[-2]  +   =  (2 bricks)
    //
    for (int i = 2; i <= 50; i++)
        p[i] = p[i-1] + p[i-2];


    int n;
    for (;;)
    {
        scanf("%d", &n);

        if (n == 0)
            break;

        printf("%lld\n", p[n]);
    }
    return 0;
}
