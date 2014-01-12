/****
 * 104 - Arbitrage
 *
 * References: 
 *   1. http://online-judge.uva.es/board/viewtopic.php?t=7292
 *   2. http://www.csie.ntnu.edu.tw/~u91029/Path2.html
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_F 21
double profit[MAX_F][MAX_F][MAX_F];
int    path[MAX_F][MAX_F][MAX_F];
int    out[MAX_F];
int    pos;
#define FOR(_i, _n) for (_i = 1; _i <= _n; _i += 1)

int main()
{
    int n;
    int i, j, k, step;
    double t;
    int entry;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &n) != EOF)
    {
        memset(profit, 0, sizeof(profit));

        FOR(i, n) FOR(j, n)
        {
            if (i != j)
                scanf("%lf", &profit[i][j][0]);
            else
                profit[i][j][0] = 1.0;
            path[i][j][0] = i;
        }

        entry = 0;
        FOR(step, n-1)
        {
            FOR(k, n) FOR(i, n) FOR(j, n)
            {
                t = profit[i][k][step - 1] * profit[k][j][0];
                if (t > profit[i][j][step])
                {
                    profit[i][j][step] = t;
                    path[i][j][step] = k;
                }
            }

            /* find if there are some path  more than 1.01 */
            FOR(i, n)
            {
                if (profit[i][i][step] > 1.01)
                {
                    entry = i;
                    break;
                }
            }

            if (entry != 0)
                break;
        }


        if (entry == 0)
            puts("no arbitrage sequence exists");
        else
        {
            pos = 0;
            out[pos++] = entry;
            i = entry;
            for (; step >= 0; step -= 1)
            {
                i = path[entry][i][step];
                out[pos++] = i;
            }

            for (i = pos-1; i >0; i-=1)
                printf("%d ", out[i]);
            printf("%d\n", out[i]);
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
