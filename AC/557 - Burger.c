/****
 * 557 - Burger
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_P 100001
int n, p;
double f[MAX_P];


int main()
{
    int i, j, k;
    int x;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    f[2] = 1.0;
    for (i = 4; i < MAX_P; i+=2)
        f[i] = f[i-2] * (i-3) / (i-2);

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &p);

        if (p == 2)
        {
            puts("0.0000");
            continue;
        }

        printf("%.4lf\n", 1.0-f[p]);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

