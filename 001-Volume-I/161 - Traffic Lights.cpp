/****
 * 161 - Traffic Lights
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MIN2(_a, _b)   (_a > _b ? _b : _a)

int t[100];
int g[100];
int n;

#define IS_GREEN(_sec, _i)  ((_sec % t[_i]) < g[_i])

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (;;)
    {
        bool done = false;
        int time, min;

        scanf("%d %d %d", &t[0], &t[1], &t[2]);

        if (t[0] == 0 && t[1] == 0)
            break;
        n = 2;
        g[0] = t[0] - 5; t[0] *= 2;
        g[1] = t[1] - 5; t[1] *= 2;
        min = MIN2(t[0], t[1]);

        if (t[2] != 0)
        {
            g[2] = t[2] - 5; t[2] *= 2;
            n++;

            while (scanf("%d", &time) != EOF && time != 0)
            {
                g[n] = time - 5;
                t[n] = time * 2;
                min = MIN2(min, t[n]);
                n++;
            }
        }

        int i, j, k;
        for (k = min; k <= 18000; k += min)
        {
            for (i = k; i <= k+ min/2; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (!IS_GREEN(i,j))
                        break;
                }

                if (j == n)
                {
                    done = true;
                    break;
                }
            }

            if (done)
                break;
        }

        if (!done)
            puts("Signals fail to synchronise in 5 hours");
        else
        {
            int hh, mm, ss;

            ss = i % 60;
            i /= 60;
            mm = i % 60;
            i /= 60;
            hh = i;

            printf("%02d:%02d:%02d\n", hh, mm, ss );
        }
    }

    return 0;
}

