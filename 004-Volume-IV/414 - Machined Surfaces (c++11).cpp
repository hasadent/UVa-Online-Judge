/****
 * 414 - Machined Surfaces
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char p[13][26];
int  s[13];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    for (;;)
    {
        scanf("%d\n", &n);
        if (n == 0) break;

        for (int i = 0; i < n; i++)
            gets(p[i]);
        memset(s, 0, sizeof(s));

        for (int i = 0; i < n; i++)
            s[i] = count_if(p[i], p[i]+26, [](const char c) { return c == ' '; });

        int m = *min_element(s, s+n);

        int r = 0;
        for (int i = 0; i < n; i++)
            r += s[i] - m;

        printf("%d\n", r);
    }

    return 0;
}
