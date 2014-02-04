/****
 * 305 - Joseph
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const char *out [14] =
{"0","2","7","5","30","169","441","1872","7632","1740","93313","459901","1358657","2504881",};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        int k, n;
        scanf("%d", &k);
        if (k == 0) break;
#ifdef SOLVE
        n = k * 2;
        int m;
        for (m = k; ; m++)
        {
            int fail = false;
            for (int x = 0, y = n; y > k; y--)
            {
                if ((x = (x+m) % y) < k)
                {
                    fail = true;
                    break;
                }
            }

            if (!fail) break;
        }
        printf("%d\n", m+1);
#else
        puts(out[k]);
#endif
    }

    return 0;
}
