/****
 * 10812 - Beat the Spread!
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

    int n, s, d;
    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d %d", &s, &d);

        int a = (s + d) / 2;
        int b = s - a;

        if (a < 0 || b < 0 || a + b != s || a - b != d)
           puts("impossible");
        else
        {
            if (a > b)
                printf("%d %d\n", a, b);
            else
                printf("%d %d\n", b, a);
        }
    }
    return 0;
}
