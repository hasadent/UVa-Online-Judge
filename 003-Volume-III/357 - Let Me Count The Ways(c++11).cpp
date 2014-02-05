/****
 * 357 - Let Me Count The Ways
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long int dp[30001];
int cent[] = {1,5,10,25,50};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    dp[0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = cent[i]; j <= 30000; j++)
            dp[j] += dp[j-cent[i]];

    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (dp[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
    }

    return 0;
}
