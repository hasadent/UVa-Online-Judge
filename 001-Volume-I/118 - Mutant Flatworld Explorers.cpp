/****
 * 118 - Mutant Flatworld Explorers
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int map[51][51];
int t[128];
char dir_c[8] = "NESW";
int fm[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(map, 0, sizeof(map));

    t['N'] = 0; t['E'] = 1; t['S'] = 2; t['W'] = 3;

    int x, y;
    scanf("%d %d", &x, &y);

    int a, b, d;
    char ch, buf[104];
    while (scanf("%d %d %c\n", &a, &b, &ch) != EOF)
    {
        d = t[ch];
        gets(buf);

        int lost = 0;
        for (char *p = buf; *p != 0; p++)
        {
            //printf("%c| %d %d %c |", *p, a, b, dir_c[d]);

            if (*p == 'R')
            {
                d = (d + 1) & 3;
            }
            else if (*p == 'L')
            {
                d = (d - 1) & 3;
            }
            else
            {
                int new_a = a + fm[d][0];
                int new_b = b + fm[d][1];

                if (new_a < 0 || new_a > x || new_b < 0 || new_b > y)
                {
                    if (map[a][b] == 0)
                    {
                        printf("%d %d %c LOST\n", a, b, dir_c[d]);
                        map[a][b] = 1;
                        lost = 1;
                        break;
                    }
                }
                else
                {
                    a = new_a;
                    b = new_b;
                }
            }

            //printf("%d %d %c \n", a, b, dir_c[d]);
        }

        if (!lost)
            printf("%d %d %c\n", a, b, dir_c[d]);
    } /* while */

    return 0;
}

