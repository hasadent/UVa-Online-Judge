/****
 * 10949 - Kids in a Grid
 */
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#define MAX_S 20004

/* LCS: Hunt-Szymanski Algorithm*/
int LCS(char *s0, int n0, char *s1, int n1)
{
    vector<int> p[128-33];
    int i, j;

    for (i = 0; i < n1; i++)
        p[s1[i]-33].push_back(i);

    vector<int> v;
    v.push_back(-1);
    for (i = 0; i < n0; i++)
    {
        int ix = s0[i] - 33;
        for (j = p[ix].size()-1; j >= 0 ; j--)
        {
            int n = p[ix][j];
            if (n > v.back())
            {
                v.push_back(n);
            }
            else {
                *lower_bound(v.begin(), v.end(), n) = n;
            }
        }
    }

    return v.size()-1;
}

int main()
{
    int t, T;
    int H, W;
    int i, j, k;
    int n[2] ,x, y;
    char grid[24][24];
    char sa[MAX_S], sb[MAX_S];
    char *ps, cc;

#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    scanf("%d", &T);
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

            *ps++ = grid[x][y];
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
            n[i]+=1;
        }/* for (i... */

        if (n[0] > n[1])
            k = LCS(sb, n[1], sa, n[0]);
        else
            k = LCS(sa, n[0], sb, n[1]);

        printf("Case %d: %d %d\n", t, n[0] - k, n[1] - k);
    }/* for (t... */

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

