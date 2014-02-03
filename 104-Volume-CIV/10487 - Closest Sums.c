/****
 * 10487 - Closest Sums
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000
#define MAX_M 25

int sum[MAX_N*MAX_N];

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int *)b;
}

int main()
{
    int case_num = 0;
    int i, j, k;
    int n, m;
    int in[MAX_N];
    int c;
    int lb, ub, mid;

    while (scanf("%d", &n) != EOF && n != 0)
    {
        case_num += 1;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &in[i]);
        }

        k = 0;
        for (i = 0; i < n; i++)
            for (j = i+1; j < n; j++)
                if (i!=j)
                    sum[k++] = in[i] + in[j];
        sum[k++] = 0x7fffffff;

        qsort(sum, k, 4, cmp);
        scanf("%d", &m);

        printf("Case %d:\n", case_num);
        for (i = 0; i < m; i++)
        {
            scanf("%d", &c);

            /* binary search */
            lb = 0;
            ub = k;
            while (lb != ub)
            {
                mid = (lb + ub) / 2;
                if (c == sum[mid])
                {
                    j = mid;
                    break;
                }
                else if (c < sum[mid])
                {
                    ub = mid;
                }
                else
                {
                    lb = mid+1;
                }

                j = lb;
            }

            /*printf("j = %d\n", j);*/
            if (j != 0 && (sum[j] - c) >= (c - sum[j-1]))
                j--;
            printf("Closest sum to %d is %d.\n", c, sum[j]);
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

