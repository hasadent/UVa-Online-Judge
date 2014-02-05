/****
 * 352 - The Seasonal War
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
char map[30][30];

void dfs(int x, int y)
{
    if (map[x][y] == '0' || x < 0 || x == n || y < 0 || y == n)
        return;

    map[x][y] = '0';
    dfs(x-1, y-1);
    dfs(x-1, y);
    dfs(x-1, y+1);
    dfs(x, y-1);
    dfs(x, y+1);
    dfs(x+1, y-1);
    dfs(x+1, y);
    dfs(x+1, y+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    while (scanf("%d\n", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            gets(map[i]);

        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (map[i][j] == '1')
                {
                    dfs(i, j);
                    count ++;
                }
        printf("Image number %d contains %d war eagles.\n", t++, count);
    }

    return 0;
}
