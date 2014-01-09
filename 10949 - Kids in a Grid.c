/****
 * 10949 - Kids in a Grid
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_S 20004
char grid[24][24];
int len[MAX_S][MAX_S];
#define MAX(a, b)  ((a) > (b) ? (a) : (b))

int main()
{
    int t, T;
    int H, W;
    int i, j;
    int n[2] ,x, y;
    char sa[MAX_S], sb[MAX_S];
    char *ps, cc;

#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    scanf("%d\n", &T);
    for (t = 1; t <= T; t++)
    {
        /* grid */
        scanf("%d %d\n", &H, &W);
        for (i = 1; i <= H; i++)
        {
            fgets(&grid[i][1], 24, stdin);
        }
        /* string */
        for (i = 0; i < 2; i++)
        {
            scanf("%d %d %d\n", &n[i], &x, &y);
            ps = i == 0 ? sa : sb;
            *ps++ = '0';
            for (j = 0; j < n[i]; j++)
            {
                scanf("%c", &cc);
                switch (cc)
                {
                case 'N':
                    *ps++ = grid[--x][y];
                    break;
                case 'S':
                    *ps++ = grid[++x][y];
                    break;
                case 'E':
                    *ps++ = grid[x][++y];
                    break;
                case 'W':
                    *ps++ = grid[x][--y];
                    break;
                }
            }
            *ps = 0;
        }/* for (i...*/

        /*printf("=== sa %s sb %s\n", sa, sb);*/
        for (i = 0; i < n[0]; i++)
            len[i][0]  = 0;
        for (i = 0; i < n[1]; i++)
            len[0][j]  = 0;

        for (i = 1; i <= n[0]; i++)
            for (j = 1; j <= n[1]; j++)
            {
                if (sa[i]==sb[j])
                    len[i][j] = len[i-1][j-1] + 1;
                else
                {
                    len[i][j] = MAX(len[i][j-1], len[i-1][j]);
                }
            }

        printf("Case %d: %d %d\n", t, n[0] - len[n[0]][n[1]], n[1] - len[n[0]][n[1]]);
    }/* for (t... */



#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

