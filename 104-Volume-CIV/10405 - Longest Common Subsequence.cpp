/****
 * 10405 - Longest Common Subsequence
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s1[1001], s2[1001];
int dp[1001][1001];
#define MAX2(_a, _b)  (_a > _b ? _a : _b)
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (gets(s1+1) != NULL)
    {
        gets(s2+1);

        int l1 = strlen(s1+1);
        int l2 = strlen(s2+1);

        memset(dp[0], 0, sizeof(dp[0]));
        for (int i = 1; i < l2; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= l1; i++)
            for (int j = 1; j <= l2; j++)
                if (s1[i] == s2[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = MAX2(dp[i-1][j], dp[i][j-1]);
                }

        printf("%d\n", dp[l1][l2]);
    }


    return 0;
}
