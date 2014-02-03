/****
 * 10003 - Cutting Sticks
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int INF = 100000;
int dp[101][101];
int p[51];

int cost(int x, int y)
{
     if (dp[x][y] != INF)
        return dp[x][y];

    for (int i = x + 1; i < y; i++)
    {
        int c = cost(x, i) + cost(i, y) + p[y] - p[x];
        if (c < dp[x][y])  dp[x][y] = c;
    }

    return dp[x][y];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int len, n;
    for (;;)
    {
        scanf("%d", &len);
        if (len == 0) break;

        scanf("%d", &n);
        p[0] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        p[n+1] = len;

        for (int i = 0; i <= n+1; i++)
            for (int j = i+2; j <= n+1; j++)
                dp[i][j] = INF;

        for (int i = 0; i <= n; i++)
            dp[i][i+1] = 0;

        printf("The minimum cutting is %d.\n", cost(0, n+1));
    }
    return 0;
}
