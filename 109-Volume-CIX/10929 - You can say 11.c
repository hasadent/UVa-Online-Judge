/****
 * 10487 - Closest Sums
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1008

int main()
{
    char buf[MAX];
    char * p = buf+4;
    int i, j;
    char * fmt[2] = {
        "%s is not a multiple of 11.\n",
        "%s is a multiple of 11.\n",
    };
    int s;

    buf[0] = buf[1] = buf[2] = buf[3] = '0';

    while (scanf("%s", p) != EOF && !(p[0] == '0' && p[1] == 0))
    {
        j = strlen(p);
        p -= 4-(j&3);
        j += 4-(j&3);

        s = 0;
        for (i = 0; i < j; i+=4)
        {
            s += (int)p[i] - p[i+1] + p[i+2] - p[i+3];
        }

        /*printf("s = %d\n", s);*/

        p = buf+4;
        printf(fmt[(s % 11) == 0], p);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

