/****
 * 272 - TeX Quotes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char cc[2] = {'`', '\''};
    char buf[256];
    char out[256];
    char *p, *q;
    int dq = 0;

    while (fgets(buf, 256, stdin) != 0)
    {
        p = buf;
        q = out;
        while (*p != 0)
        {
            if (*p =='"')
            {
                *q++ = cc[dq];
                *q++ = cc[dq];
                dq = dq ^ 1;
            }
            else
            {
                *q++ = *p;
            }
            p++;
        }
        *q = 0;
        fputs(out, stdout);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

