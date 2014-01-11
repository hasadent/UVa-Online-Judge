/****
 * 10035 - Primary Arithmetic
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Y 1024


int main()
{
    int i, j, k;
    int count, carry;;
    char x[24], y[24];
    char *p, *q;
    int lenp, lenq;


#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    for (i = 0; i < 12; i++)
        x[i] = y[i] = '0';

    for(;;)
    {
        p = x+12;
        q = y+12;

        scanf("%s %s\n", p, q);

        if(*p == '0' && *q == '0')
            break;

        lenp = strlen(p);
        lenq = strlen(q);

        if (lenp > lenq)
        {
            q -= (lenp - lenq);
            lenq = lenp;
        }
        else
        {
            p -= (lenq - lenp);
            lenp = lenq;
        }

        p += lenq-1;
        q += lenq-1;
        carry = 0;
        count = 0;
        for (i = lenp; i >=0; i--)
        {
            if ((carry + *p + *q) >= (10 + '0' + '0'))
            {
                carry = 1;
                count += 1;
            }
            else
            {
                carry = 0;
            }

            p--; q--;
        }

        if (count == 0)
            puts("No carry operation.");
        else if (count == 1)
            puts("1 carry operation.");
        else
            printf("%d carry operations.\n", count);

    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
