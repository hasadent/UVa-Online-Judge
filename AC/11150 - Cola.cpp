/****
 * 11150 - Cola
 */
#include <iostream>
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

    int n;

    while (scanf("%d", &n) != EOF)
    {
        int d = 0, e = 1;

        while (n > 0)
        {
            d += n;
            e += n;

            n = e / 3;
            e = e % 3;
        }


        printf("%d\n", d);
    }
    return 0;
}
