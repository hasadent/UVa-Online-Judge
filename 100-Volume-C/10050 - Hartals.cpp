/****
 * 10050 - Hartals
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int day[3652];
int p_s[100];
int s = 0;


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
        int n, p, m;
        scanf("%d %d", &n, &p);

        for (int i = 1; i <= n; i++)
            day[i] = 0;

        s = 0;

        while (p-- > 0)
        {
            scanf("%d", &m);
            if (day[m] == 0)
            {
                p_s[s++] = m;
                day[m] = 1;
            }
        }

        for (int i = 0; i < s; i++)
        {
            int m = p_s[i];
            for (int i = m; i <= n; i += m)
                day[i] = 1;
        }

        for (int i = 6; i <= n; i+=7)
            day[i] = day[i+1] = 0;

        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += day[i];

        printf("%d\n", sum);
    }
    return 0;
}
