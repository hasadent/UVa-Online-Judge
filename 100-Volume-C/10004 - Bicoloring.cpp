/****
 * 10004 - Bicoloring
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 200

int n;
int color[MAX_N];
vector<int> edges[MAX_N];

#define NONE  0
#define BLACK 1
#define WHITE 2

bool is_colored_black(int x)
{
    return color[x] == BLACK;
}

bool is_colored_white(int x)
{
    return color[x] == WHITE;
}

bool dfs(int x)
{
    if (count_if(edges[x].begin(), edges[x].end(), is_colored_black) == 0)
    {
        color[x] = BLACK;

        bool result = true;
        for (size_t i = 0; i < edges[x].size(); i++)
        {
            int v = edges[x][i];
            if (color[v] == NONE)
                result = result && dfs(v);
        }
        if (result)
            return true;

        color[x] = NONE;
    }

    if (count_if(edges[x].begin(), edges[x].end(), is_colored_white) == 0)
    {
        color[x] = WHITE;

        bool result = true;
        for (size_t i = 0; i < edges[x].size(); i++)
        {
            int v = edges[x][i];
            if (color[v] == NONE)
                result = result && dfs(v);
        }
        if (result)
            return true;

        color[x] = NONE;
    }

    return false;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            color[i] = 0;
            edges[i].clear();
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        if (dfs(0))
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
