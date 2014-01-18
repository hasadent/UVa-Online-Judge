/****
 * 146 - ID Codes
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int count[26];
char buf[100];
int len;

int dfs(int lv, int from)
{
    if (lv == len)
    {
        buf[lv] = 0;
        return 1;
    }

    for (int i = from; i < 26; i++)
    {
        if (count[i] > 0)
        {
            count[i] --;

            buf[lv] = 'a' + i;
            if (dfs(lv+1, 0) == 1)
                return 1;
            count[i] ++;
        }
    }

    return 0;
}

int main()
{
    int n, i;
    int lv, from;
    bool done;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (gets(buf) != NULL && buf[0] != '#')
    {
        done = false;
        memset(count, 0, sizeof(count));

        len = strlen(buf);

        for (lv = len - 1; buf[0] != 0; lv--)
        {
            from = buf[lv] - 'a';
            buf[lv] = 0;
            count[from] += 1;
            if (dfs(lv, from + 1) == 1)
            {
                puts(buf);
                done = true;
                break;
            }
        }

        if (!done)
            puts("No Successor");

    }

    return 0;
}
