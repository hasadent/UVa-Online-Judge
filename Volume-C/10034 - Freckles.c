/****
 * 10034 - Freckles
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N     100
#define POW2(x)  ((x)*(x))

int T, N, E;

struct coordinate
{
    float x, y;
};
struct coordinate c[MAX_N];

struct edge{
    int src;
    int dst;
    float w;
};
struct edge e[MAX_N * (MAX_N-1) / 2];
struct edge *pe[MAX_N * (MAX_N-1) / 2];

int cmp(const void *a, const void *b)
{
    float fa = (*(struct edge**)a)->w;
    float fb = (*(struct edge**)b)->w;
    if (fa > fb) return 1;
    else if (fa < fb) return -1;
    return 0;
}

int sc = 0;
int set[MAX_N];
#define INIT_SET(_i)           for (_i = 0; _i < N; _i++) { set[_i] = _i; } sc = N-1;
#define SET(x)                 find_set((x))
#define FAST_UNION(fs_x, fs_y) { set[(fs_x)] = (fs_y); sc --; }
#define UNION(x, y)            if (SET((x)) != SET((y))) { set[find_set(x)] = find_set(y); sc --; }
int find_set(int i)
{
    if (set[i] == i)
        return i;
    return (set[i] = find_set(set[i]));
}

int kruskal()
{
    int i, p_src, p_dst;
    float weight = 0;

    /*for (i = 0; i < m; i++)
        printf(">>%d %d %d\n", pe[i]->src, pe[i]->dst, pe[i]->w);*/
    for (i = 0; i < E && sc > 0; i++)
    {
        if ((p_src = SET(pe[i]->src)) != (p_dst = SET(pe[i]->dst)))
        {
            FAST_UNION(p_src, p_dst);

            weight += sqrt(pe[i]->w);
        }
    }

    printf("%.2f\n", weight);
    return sc == 0;
}

int main()
{
    int i, j;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
        {
            scanf("%f %f", &c[i].x, &c[i].y);
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

        INIT_SET(i);
        qsort(pe, E, sizeof(pe[0]), cmp);

        /* In this problem, there are always soultions */
        kruskal();

        if (T != 0)
            puts("");
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

