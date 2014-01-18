/****
 * 195 - Anagram
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int count[52];
char map[54];
char buf[100];
int len;

void dfs(int lv)
{
    if (lv == len)
    {
        buf[lv] = 0;
        puts(buf);
        return;
    }

    for (int i = 0; i < 52; i++)
    {
        if (count[i] > 0)
        {
            count[i] --;

            buf[lv] = map[i];
            dfs(lv+1);

            count[i] ++;
        }
    }
}

int main()
{
    int n, i;

    for (i = 0; i < 26; i++)
    {
        map[i*2] = 'A' + i;
        map[i*2+1] = 'a' + i;
    }

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d\n", &n);
    while (n-- > 0)
    {
        gets(buf);

        memset(count, 0, sizeof(count));
        for (i = 0; buf[i] != 0; i++)
            count[(((buf[i] | 0x20) - 'a') << 1) + ((buf[i] & 0x20) >> 5)]++;
        len = i;

        dfs(0);
    }

    return 0;
}
