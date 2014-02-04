/****
 * 10019 - Funny Encryption Method
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int bn[16] = {
    0, 1, 1, 2,
    1, 2, 2, 3,
    1, 2, 2, 3,
    2, 3, 3, 4,
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, v;
    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &v);

        int b1 = 0;
        for (int x1 = v; x1 != 0; b1 += bn[x1 & 0xf], x1 >>= 4);

        int b2 = 0;
        for (int x2 = v; x2 != 0; b2 += bn[x2 % 10], x2 /= 10);

        printf("%d %d\n", b1, b2);
    }

    return 0;
}
