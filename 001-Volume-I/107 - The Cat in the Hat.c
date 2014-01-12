/****
 * 107 - The Cat in the Hat
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MOD(v0, v1)   ((v0) % (v1))

int main()
{
    int x, y;
    int n, m;
    int i, j;
    unsigned int cat, sum;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        scanf("%d %d", &x, &y);

        if (x == 0 && y == 0)
            break;

        if (x == 1)
        {
            puts("0 1");
            continue;
        }
        else if (y == 1)
        {
            n = 1;
            m = 2;
        }
        else if (x - y == 1)
        {
            /*n = y;*/
            printf("1 %d\n", x+y);
            continue;
        }
        else
        {
            for (n = 2; ; n++)
            {
                m = n+1;
                i = x;
                j = y;
                while (i % m == 0 && j % n == 0)
                {
                    i /= m;
                    j /= n;
                }
                if (i == 1 && j == 1)
                    break;
            }
        }

        cat = -y; /* total cats     */
        sum = 0;  /* total height   */
        /* x  */  /* current height */
        y = 1;    /* current cats   */
        while (x >= 1)
        {
            cat += y;
            sum += x * y;

            x /= n+1;
            y *= n;
        }
        printf("%d %d\n", cat, sum);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
