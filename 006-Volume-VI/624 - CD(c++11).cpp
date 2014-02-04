/****
 * 624 - CD
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int left_min;
vector<int> a;
vector<int> s;

bool visited[20];
int m[20];
int n, t;


void dfs(int now, int left)
{
    if (left < 0)
    {
        return;
    }

    if (now >= t || left == 0)
    {
        if (left < left_min)
        {
            left_min = left;
            a = s;
        }
        return ;
    }


    for (int i = now; i < t; i++)
        if (!visited[i])
        {
            visited[i] = true;
            s.push_back(m[i]);
            dfs(i+1, left-m[i]);
            s.pop_back();
            visited[i] = false;
        }

    dfs(t, left);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d %d", &n, &t) != EOF)
    {
        for (int i = 0; i < t; i++)
            scanf("%d", &m[i]);

        memset(visited, 0, sizeof(visited));
        a.clear();
        s.clear();
        left_min = n;

        dfs(0, n);

        for(int i : a)
            printf("%d ", i);
        printf("sum:%d\n", n - left_min);
    }

    return 0;
}
