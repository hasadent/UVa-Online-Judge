/****
 * 445 - Marvelous Mazes
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

char buf[136];
char ch[128];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (int i = 'A'; i <= 'Z'; i++) ch[i] = i;
    ch['*'] = '*';
    ch['b'] = ' ';
    ch['!'] = '\n';

    while (gets(buf) != NULL)
    {

        int x = 0;
        for (char *p = buf; *p != 0; p++)
        {
            if ('0' <= *p && *p <= '9')
                x += *p - '0';
            else if (*p == '!')
                puts("");
            else
            {
                for (; x > 0; x--)
                    putchar(ch[*p]);
            }
        }
        puts("");
    }

    return 0;
}
