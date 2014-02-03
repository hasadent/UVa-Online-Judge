/****
 * 417 - Word Index
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int value = 1;
map<string , int> m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char buf[6];
    memset(buf, 0, sizeof(buf));
    for (buf[0] = 'a'; buf[0] <= 'z'; buf[0]++)
        m[buf] = value++;

    for (buf[0] = 'a'; buf[0] <= 'z'; buf[0]++)
        for (buf[1] = buf[0]+1; buf[1] <= 'z'; buf[1]++)
            m[buf] = value++;

    for (buf[0] = 'a'; buf[0] <= 'z'; buf[0]++)
        for (buf[1] = buf[0]+1; buf[1] <= 'z'; buf[1]++)
            for (buf[2] = buf[1]+1; buf[2] <= 'z'; buf[2]++)
                m[buf] = value++;

    for (buf[0] = 'a'; buf[0] <= 'z'; buf[0]++)
        for (buf[1] = buf[0]+1; buf[1] <= 'z'; buf[1]++)
            for (buf[2] = buf[1]+1; buf[2] <= 'z'; buf[2]++)
                for (buf[3] = buf[2]+1; buf[3] <= 'z'; buf[3]++)
                    m[buf] = value++;

    for (buf[0] = 'a'; buf[0] <= 'z'; buf[0]++)
        for (buf[1] = buf[0]+1; buf[1] <= 'z'; buf[1]++)
            for (buf[2] = buf[1]+1; buf[2] <= 'z'; buf[2]++)
                for (buf[3] = buf[2]+1; buf[3] <= 'z'; buf[3]++)
                    for (buf[4] = buf[3]+1; buf[4] <= 'z'; buf[4]++)
                        m[buf] = value++;


    while (gets(buf) != NULL)
    {
        int valid = true;

        int i;
        for (i = 1; buf[i] != 0; i++)
            if (buf[i] <= buf[i-1])
            {
                valid = false;
                break;
            }

        if (!valid)
        {
            puts("0");
            continue;
        }

        printf("%d\n", m[buf]);
    }
    return 0;
}
