/****
 * 116 - Unidirectional TSP
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_M 10
#define MAX_N 100
int matrix[MAX_M][MAX_N];
int weight[MAX_M][MAX_N];
int next[MAX_M][MAX_N];

int case_lb[3];
int case_ub[3];

int main()
{
    int m, n;
    int min_v, min_i, t;
    int i, j;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d %d", &m, &n) != EOF)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                scanf("%d", &matrix[i][j]);
        }

        if (m == 1)
        {
            min_v = matrix[0][0];

            printf("1");
            for (j = 1; j < n; j++)
            {
                min_v += matrix[0][j];
                printf(" 1");
            }    
            printf("\n%d\n", min_v);
            continue;
        }

        for (i = 0; i < m; i++)
        {
            weight[i][n-1] = matrix[i][n-1];
            next[i][n-1]  = -1;
        }

        case_lb[0] = 0;
        case_lb[1] = 1;
        case_lb[2] = m-1;

        case_ub[0] = 0;
        case_ub[1] = m-2;
        case_ub[2] = m-1;

        for (j = n-2; j >=0; j--)
            for (i = 0; i < m; i++)
            {
#define MIN2(_a, _b)      (weight[_a][j+1] > weight[_b][j+1] ? (_b) : (_a))
#define MIN3(_a, _b, _c)  MIN2(MIN2(_a, _b),_c)
                if   (i == 0)
                {
                    min_i = MIN3(case_lb[0], case_lb[1], case_lb[2]);
                }
                else if (i == m-1)
                {
                    min_i = MIN3(case_ub[0], case_ub[1], case_ub[2]);
                }
                else
                {
                    min_i = MIN3(i-1, i, i+1);
                }

                next[i][j]   = min_i;
                weight[i][j] = weight[min_i][j+1] + matrix[i][j];

            }

        min_i = 0;
        min_v = weight[0][0];
        for (i = 1; i < m; i++)
        {
            if (weight[i][0] < min_v)
            {
                min_v = weight[i][0];
                min_i = i;
            }
        }

        j = 1;
        i = next[min_i][0];
        printf("%d", min_i+1);
        while (i != -1)
        {
            printf(" %d", i+1);

            i = next[i][j];
            j = j + 1;
        }
        printf("\n%d\n", min_v);
    }


#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
