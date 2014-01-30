/****
 * 12468 - Zapping
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char buf[136];
char ch[128];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (;;)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a == -1) break;

        int x = a > b ? a - b : b - a;
        int y = 100 - x;

        printf("%d\n", x < y ? x : y);
    }
    return 0;
}
