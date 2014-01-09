/****
 * 11946 - Code Number
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char ascii[96] = {
/* 00 */  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/* 10 */  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/* 20 */ 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
/* 30 */'O','I','Z','E','A','S','G','T','B','P', 58, 59, 60, 61, 62, 63,
/* 40 */ 64,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
/* 50 */'P','Q','R','S','T','U','V','W','X','Y','Z',  0,  0,  0,  0,  0,
};

int main()
{
    int T, i;
    char buf[100];
    char *p;

    scanf("%d\n", &T);
    while (T--)
    {
        while (gets(buf))
        {
            if (buf[0] == 0) break;

            for (i = 0; (buf[i] = ascii[buf[i]]) != 0; i++);

            puts(buf);
        }

        if (T)
          puts("");
    }
    return 0;
}

