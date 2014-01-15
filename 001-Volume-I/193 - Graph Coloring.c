/****
 * 193 - Graph Coloring
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

typedef struct vertex
{
    int edge[MAX_N];
    int c;
    int colored;
} vertex;

int n, k;
vertex v[MAX_N+1];
#define ADD_EDGE(_v, _e)   v[_v].edge[v[_v].c++] = _e;
#define EDGE(_x, _y)       (v[_x].edge[_y])
int max_black;
int black_list[MAX_N];

void search(int x, int colored_num)
{
    int i, j;
    int can_color_black;

    if (x > n)
    {
        if (colored_num > max_black)
        {
            max_black = colored_num;
            for (i = 1, j = 0; i <= n; i++)
                if (v[i].colored == 1)
                    black_list[j++] = i;
        }
        return;
    }

    if (colored_num + (n - x + 1) <= max_black)
        return;

    can_color_black = 1;
    for (i = 0; i < v[x].c; i++)
        if (v[EDGE(x, i)].colored == 1)
        {
            can_color_black = 0;
            break;
        }

    if (can_color_black)
    {
        v[x].colored = 1;
        search(x+1, colored_num+1);
        v[x].colored = 0;
    }

    search(x+1, colored_num);
}

int main()
{
    int T;
    int x, y;
    int i;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T-- > 0)
    {
        scanf("%d %d", &n, &k);

        for (i = 1; i <= n; i++)
        {
            v[i].c = 0;
            v[i].colored = 0;
        }

        for (i = 0; i < k; i++)
        {
            scanf("%d %d", &x, &y);
            ADD_EDGE(x, y);
            ADD_EDGE(y, x);
        }

        max_black = 0;
        search(1, 0);

        printf("%d\n%d", max_black, black_list[0]);
        for (i = 1; i < max_black; i++)
            printf(" %d", black_list[i]);
        printf("\n");
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
