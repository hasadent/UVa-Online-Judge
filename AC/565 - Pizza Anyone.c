/****
 * 565 - Pizza Anyone
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 120

int main()
{
    int n;
    char buf[40], c;
    int choice[MAX_N];
    int mask[MAX_N];
    int accept, offer;
    int i, j;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    for (;;)
    {
        for (n = 0; ; n++)
        {
            choice[n] = 0;
            mask[n] = 0;

            if (fgets(buf, 40, stdin) == 0)
            {
                break;
            }

            if (buf[0] == '.')
            {
                break;
            }

            for (i = 0; buf[i] != ';'; i+=2)
            {
                accept = (buf[i] >> 1) & 1; /* '+' -> 1 , '-' -> 0 */
                offer  = buf[i+1] - 'A';
                choice[n] |= (accept << offer);
                mask[n]   |= (1 << offer);
            }
        }

        if (n == 0)
            break;

        for (i = 0; i < 65536; i++)
        {
            for (j = 0; j < n; j++)
                if (((~(choice[j] ^ i)) & mask[j]) == 0)
                    break;

            if (j == n)
                break;
        }

        if (i == 65536)
            puts("No pizza can satisfy these requests.");
        else
        {
            printf("Toppings: ");
            c = 'A';
            while (i != 0)
            {
                if ((i & 1) == 1)
                    putchar(c);
                i >>= 1;
                c += 1;
            }
            putchar('\n');
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

