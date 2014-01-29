/****
 * 541 - Error Correction
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int x[100];
    int y[100];

    int n;
    for (;;)
    {
        scanf("%d", &n);

        if (n == 0) break;

        memset(x, 0, n*sizeof(x[0]));
        memset(y, 0, n*sizeof(y[0]));
        int z;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &z);
                x[i] += z;
                y[j] += z;
            }

        int sum_x = 0, sum_y = 0;
        int last_x = -1, last_y = -1;

        for (int i = 0; i < n; i++)
        {
            sum_x += x[i] & 1;
            sum_y += y[i] & 1;
            if ((x[i] & 1) == 1) last_x = i;
            if ((y[i] & 1) == 1) last_y = i;
        }

        if (sum_x == 0 && sum_y == 0)
            puts("OK");
        else if (sum_x == 1 && sum_y == 1)
            printf("Change bit (%d,%d)\n", last_x+1, last_y+1);
        else
            puts("Corrupt");
    }

    return 0;
}
