/****
 * 11498 - Division of Nlogonia
 */
#include <stdio.h>

int main()
{
    int k, n, m, x, y;
    int i;
    char out[4];

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    out[2] = 0;

    while (scanf("%d", &k) != EOF)
    {
        scanf("%d %d", &n ,&m);
        for (i = 0; i < k; i++)
        {
            scanf("%d %d", &x ,&y);

            if (x == n || y == m)
            { puts("divisa"); continue; }

            out[0] = y > m ? 'N' : 'S';
            out[1] = x > n ? 'E' : 'O';
            puts(out);
        }
    }

    return 0;
}
