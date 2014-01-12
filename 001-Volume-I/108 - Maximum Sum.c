/****
 * 108 - Maximum Sum
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

int m[MAX_N][MAX_N];
int solved[MAX_N][MAX_N][MAX_N][MAX_N];
#define FROM_X_LB 0
#define FROM_X_UB 1
#define FROM_Y_LB 2
#define FROM_Y_UB 3

int find_max_sum(int x_lb, int x_ub, int y_lb, int y_ub)
{
    int i, j;
    int sub_sum[4] = {0, 0, 0, 0};
    int sum, max;
    int x_sum[MAX_N];
    int y_sum[MAX_N];

    if (solved[x_lb][x_ub][y_lb][y_ub] == 1)
        return 0;
    solved[x_lb][x_ub][y_lb][y_ub] = 1;

    memset(x_sum, 0, sizeof(x_sum));
    memset(y_sum, 0, sizeof(y_sum));
    max = 0;

    for (i = x_lb; i <= x_ub; i+=1)
        for (j = y_lb; j <= y_ub; j+=1)
        {
            x_sum[i] += m[i][j];
            y_sum[j] += m[i][j];
        }

    sum = 0;
    for (i = x_lb; i <= x_ub; i++)
    {
        sum += x_sum[i];
        if (sum < 0 && i != x_ub && x_sum[i+1] > 0)
        {
            sub_sum[FROM_X_LB] = find_max_sum(i + 1, x_ub, y_lb, y_ub);
            break;
        }
    }

    sum = 0;
    for (i = x_ub; i >= 0; i--)
    {
        sum += x_sum[i];
        if (sum < 0 && i != 0 && x_sum[i-1] > 0)
        {
            sub_sum[FROM_X_UB] = find_max_sum(x_lb, i - 1, y_lb, y_ub);
            break;
        }
    }

    sum = 0;
    for (i = y_lb; i <= y_ub; i++)
    {
        sum += y_sum[i];
        if (sum < 0 && i != y_ub && y_sum[i+1] > 0)
        {
           sub_sum[FROM_Y_LB] = find_max_sum(x_lb, x_ub, i + 1, y_ub);
           break;
        }
    }

    sum = 0;
    for (i = y_ub; i >= 0; i--)
    {
        sum += y_sum[i];
        if (sum < 0 && i != 0 && y_sum[i-1] > 0)
        {
            sub_sum[FROM_Y_UB] = find_max_sum(x_lb, x_ub, y_lb, i - 1);
            break;
        }
    }

    max = 0;
    for (i = 0; i < 4; i++)
    {
        if (sub_sum[i] > max)
            max = sub_sum[i];
    }
    if (max == 0)
        for (i = x_lb; i <= x_ub; i++)
            max += x_sum[i];
    return max;
}

int main()
{
    int n;
    int i, j, k, l;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    /*memset(solved, 0, sizeof(solved));*/

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i+=1)
        for (j = 0; j < n; j+=1)
        for (k = 0; k < n; k+=1)
        for (l = 0; l < n; l+=1)
            solved[i][j][k][l] = 0;

        for (i = 0; i < n; i+=1)
            for (j = 0; j < n; j+=1)
                scanf("%d", &m[i][j]);

        printf("%d\n", find_max_sum(0, n-1, 0, n-1));
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
