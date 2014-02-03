/****
 * 713 - Adding Reversed Numbers
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

inline void reverse(char * str, int len)
{
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char buf1[220], buf2[220];
    char *in1 = buf1 + 1, *in2 = buf2 + 1;

    int n;
    scanf("%d", &n);
    while (n-- > 0)
    {
        in1[-1] = in2[-1] = '0';
        scanf("%s %s", in1, in2);

        int len1 = strlen(in1);
        int len2 = strlen(in2);

        char *p = in1, *q = in2;
        int len = len2, slen = len1;
        if (len1 < len2)
        {
            p = in2;
            q = in1;
            len = len1;
            slen = len2;
        }

        for (int i = 0; i < len; i++)
            p[i] += q[i] - '0';

        reverse(p, slen);
        for (int i = slen - 1; i >= 0; i--)
            if (p[i] > '9')
            {
                p[i] -= 10;
                p[i-1] += 1;
            }

        p--; slen ++;
        while (*p == '0') { p++; slen --; }

        reverse(p, slen);
        while (*p == '0') { p++; }

        printf("%s\n", p);
    }
    return 0;
}
