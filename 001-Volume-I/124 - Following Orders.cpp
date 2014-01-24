/****
 * 124 - Following Orders
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char buf[1024];
int n;
int num[26];
int less_map[26][26];

void dfs(int lv)
{
    if (lv == n)
    {
        buf[lv] = 0;
        puts(buf);
        return;
    }

    for (int i = 0; i < 26; i++)
        if (num[i] == 1)
        {
            bool fail = false;
            for (int j = 0; j < lv; j++)
                    if (less_map[buf[j]-'a'][i] == 1)
                    {
                        fail = true;
                        break;
                    }

            if (!fail)
            {
                num[i] = 0;
                buf[lv] = 'a' + i;
                dfs(lv+1);
                num[i] = 1;
            }
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    bool first = true;
    while (gets(buf) != NULL)
    {
        memset(num, 0 , sizeof(num));
        memset(less_map, 0, sizeof(less_map));

        n = 0;
        for (int i = 0; buf[i] != 0; i++)
            if ('a' <= buf[i] && buf[i] <= 'z')
                { num[buf[i]-'a'] ++; n++; }

        gets(buf);
#if 0
        vector<int> vx;
        for (int i = 0; buf[i] != 0; i++)
            if ('a' <= buf[i] && buf[i] <= 'z')
                vx.push_back(buf[i] - 'a');
        for (size_t i = 0; i < vx.size(); i+=2)
            less_map[vx[i+1]][vx[i]] = 1;
#else
        int i;
        for (i = 0; buf[i+3] != 0; i+=4)
        {
            less_map[buf[i+2]-'a'][buf[i]-'a'] = 1;
        }
        less_map[buf[i+2]-'a'][buf[i]-'a'] = 1;
#endif
        if (!first)
            puts("");
        first = false;
        dfs(0);
    }

    return 0;
}

