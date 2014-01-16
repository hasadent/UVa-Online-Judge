/****
 * 160 - Factors and Factorials
 */
#include <stdio.h>
#include <stdlib.h>

int prime_list[25] =
{
 2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97,
};

int prime_count[25];

int main()
{
    int n, m;
    int x, y;
    int i;
    int c;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &n) != EOF && n != 0)
    {
        memset(prime_count, 0, sizeof(prime_count));

        x = 1;
        for (m = n; m >= 1; m--)
        {
            x *= m;

            /* 2 */
            for (c = 0; (x & 1) == 0; c++, x >>= 1);
            prime_count[0] += c;

            for (i = 1; i < 25 && prime_list[i] <= x; i++)
            {
                for (c = 0;
                    x % prime_list[i] == 0;
                    c++, x /= prime_list[i]);
                prime_count[i] += c;
            }
        }

        printf("%3d! =", n);
        for (i = 0, c = 0; i < 25; i++)
            if (prime_count[i] != 0)
            {
                if (c == 15)
                    printf("\n      ");
                printf("%3d", prime_count[i]);
                c++;
            }
        printf("\n");
    }

#ifndef ONLINE_JUDGE
    /*system("pause");*/
#endif
    return 0;
}


