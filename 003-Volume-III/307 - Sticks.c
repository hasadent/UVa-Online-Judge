/****
 * 307 - Sticks
 */
#include <stdio.h>
#include <stdlib.h>

int n;
int num[51];
int sum;
int left;
int value;
int sorted[100];
int visited[100];

int dfs(int x, int local_sum)
{
    int i;
    int y;

    for (i = x; i < n; i++)
    {
        if (visited[i] == 1) continue;

        if (i && visited[i-1] == 0 && sorted[i] == sorted[i-1]) continue;

        y = sorted[i] + local_sum;
        if (y  > value)
            continue;

        else if (y == value)
        {
            visited[i] = 1, left --;

            if (left == 0)
                return 1;

            if (dfs(0, 0) == 1)
                return 1;

            visited[i] = 0, left ++;

            return 0;
        }
        else
        {
            visited[i] = 1, left --;

            if (dfs(i+1, y) == 1)
                return 1;

            visited[i] = 0, left ++;

            /* the first iteration must has a solution */
            if (local_sum == 0)
                return 0;
        }
    }
    return 0;
}

int main()
{
    int i, j, k;
    int x;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &n) != EOF && n != 0)
    {
        for (i = 1; i <= 50; i++)
            num[i] = 0;

        sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &x);
            num[x] += 1;
            sum += x;
        }

        k = 0;
        for (i = 50; i > 0; i--)
        {
            for (j = 0; j < num[i]; j++)
                sorted[k++] = i;
        }

        for(value = sorted[0]; value <= sum; value ++)
        {
            if((sum % value) != 0)
                continue;

            /* init */
            for (i = 0; i < n; i++)
                visited[i] = 0;
            left = n;

            if (dfs(0, 0) == 1)
            {
                break;
            }
        }

        printf("%d\n", value);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

