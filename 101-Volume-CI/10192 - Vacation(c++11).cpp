/****
 * 10192 - Vacation
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int dp[104][104];
char city1[104], city2[104];
#define MAX2(_a, _b)  (_a > _b ? _a : _b)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (int T = 1; ; T++)
    {
        gets(city1+1);
        if (city1[1] == '#') break;
        gets(city2+1);

        int n1 = strlen(city1+1);
        int n2 = strlen(city2+1);

        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                if (city1[i] == city2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = MAX2(dp[i-1][j], dp[i][j-1]);

        printf("Case #%d: you can visit at most %d cities.\n", T, dp[n1][n2]);
    }

    return 0;
}
