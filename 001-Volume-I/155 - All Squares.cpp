/****
 * 155 - All Squares
 *
 */
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

    for (;;)
    {
        int k, y, x;
        scanf("%d %d %d", &k, &x, &y);
        if (k == 0)
            break;

        int p = 1024, q = 1024;
        int in_square = 0;

        for (; k > 0; k /= 2)
        {
            //printf("%d > %d %d | %d %d\n", k, x, y, p, q);

            int lp = p - k;
            int up = p + k;
            int lq = q - k;
            int uq = q + k;


            if (lp <= x && x <= up && lq <= y && y <= uq)
            {
                in_square += 1;
            }

            p = (p > x ? lp : up);
            q = (q > y ? lq : uq);

        }

        printf("%3d\n", in_square);
    }

    return 0;
}

