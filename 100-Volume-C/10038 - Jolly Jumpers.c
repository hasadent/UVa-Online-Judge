/****
 * 10038 - Jolly Jumpers
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3000
int num[MAX_N];
char test[MAX_N];
const char *output[2] = {"Not jolly", "Jolly"};
#define ABS_SUB(a, b)   (a > b ? a - b : b - a)

int main()
{
    int n, sum;
    int isjj, i;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &num[i]);

        memset(test, 0, sizeof(char)*n);

        for (i = 1; i < n; i++)
            test[ABS_SUB(num[i-1], num[i])] = 1;

        sum = 0;
        for (i = 1; i < n; i++)
            sum += test[i];

        puts(output[sum == n-1]);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
