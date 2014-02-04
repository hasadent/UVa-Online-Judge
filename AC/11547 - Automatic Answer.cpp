/****
 * 11547 - Automatic Answer
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

    int t;
    scanf("%d", &t);
    while (t-- > 0)
    {
        int n;
        scanf("%d", &n);

        int x = 315 * n + 36962;
        if (x < 0) x = -x;
        printf("%d\n", x%100/10);
    }

    return 0;
}
