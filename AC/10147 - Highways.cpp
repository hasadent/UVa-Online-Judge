/****
 * 10147 - Highways
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_N 750
#define MAX_M 1000
#define POW2(x) ((x)*(x))

int T, N, M, E;
int sc = 0;
int set[MAX_N];
#define INIT_SET(_i)           for (_i = 0; _i < N; _i++) { set[_i] = _i; } sc = N-1;
#define SET(x)                 find_set((x))
#define FAST_UNION(fs_x, fs_y) { set[(fs_x)] = (fs_y); sc --; }
#define UNION(x, y)            if (SET((x)) != SET((y))) { set[find_set(x)] = find_set(y); sc --; }

struct coordinate
{
    int x, y;
};
struct coordinate c[MAX_N];

struct edge{
    int src;
    int dst;
    int w;
};
struct edge e[MAX_N * (MAX_N-1) / 2];
struct edge * pe[MAX_N * (MAX_N-1) / 2];

#if 0
int cmp(const void *a, const void *b)
{
    return (*(struct edge**)a)->w - (*(struct edge**)b)->w;
}
#endif

bool cmp(const struct edge * a, const struct edge * b)
{
    return a->w < b->w;
}

int find_set(int i)
{
    if (set[i] == i)
        return i;
    else
       return (set[i] = find_set(set[i]));
}

int kruskal()
{
    int i, p_src, p_dst, built = 0;

    for (i = 0; i < E && sc > 0; i++)
    {
        if ((p_src = SET(pe[i]->src)) != (p_dst = SET(pe[i]->dst)))
        {
            FAST_UNION(p_src, p_dst);
            printf("%d %d\n", pe[i]->src+1, pe[i]->dst+1);
            built ++;
        }
    }

    if (built == 0)
    {
        printf("No new highways need\n");
    }

    return sc == 0;
}

int main()
{
    int i, j;
    int in0, in1;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
        {
            scanf("%d %d", &c[i].x, &c[i].y);
        }

        E = 0;
        for (i = 0; i < N; i++)
            for (j = i+1; j < N; j++)
            {
                e[E].src = i;
                e[E].dst = j;
                e[E].w = POW2(c[i].x - c[j].x) + POW2(c[i].y - c[j].y);
                pe[E] = &e[E];
                E++;
            }

        /*qsort(pe, E, sizeof(pe[0]), cmp);*/
        sort(pe, pe+E, cmp);

        INIT_SET(i);
        scanf("%d", &M);
        for (i = 0; i < M; i++)
        {
            scanf("%d %d", &in0, &in1);
            UNION(in0-1, in1-1);
        }

        /* In this problem, there are always solutions */
        kruskal();

        if (T)
            printf("\n");
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

