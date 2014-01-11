/****
 * 10018 - Reverse and Add
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_R     10
int N;


#define TEST_PALINDROME(TF, str, h, t) \
{ \
    TF = 1; \
    while (h < t) \
        if (str[h++] != str[t--])  \
        { TF = 0; break; } \
}

#define REVERSE(str, h, t, __t) \
    while (h < t) \
    { \
        __t = str[h]; str[h] = str[t]; str[t] = __t; \
        h++, t--; \
    }


int main()
{
    int i, j;
    unsigned int p, r;
    int c, len, tf;
    char buf[14], t;

    scanf("%d", &N);
    while (--N >= 0)
    {
        scanf("%s", buf);
        c = 0;
        len = strlen(buf);

        for (;;)
        {
            i = 0; j = len -1;
            TEST_PALINDROME(tf, buf, i, j);
            if (tf)
                break;

            p = atoi(buf);

            /* reverse */
            i = 0; j = len - 1;
            REVERSE(buf, i, j, t);
            r = atoi(buf);

            /* add */
            sprintf(buf, "%u", p+r);

            while (buf[len] != 0) len++;
            c++;
        }

        printf("%d %s\n", c, buf);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

