/****
 * 10369 - Arctic Network
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_P     500
#define POW2(x)  ((x)*(x))

int T, S, P, E;

struct coordinate
{
    int x, y;
};
struct coordinate c[MAX_P];

struct edge{
    int src;
    int dst;
    int w;
};
struct edge e[MAX_P * (MAX_P-1) / 2];
struct edge *pe[MAX_P * (MAX_P-1) / 2];

int cmp(const void *a, const void *b)
{
    return  (*(struct edge**)a)->w - (*(struct edge **)b)->w;
}

int sc = 0;
int set[MAX_P];
#define INIT_SET(_i)           for (_i = 0; _i < P; _i++) { set[_i] = _i; } sc = P-1;
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

    /*for (i = 0; i < m; i++)
        printf(">>%d %d %d\n", pe[i]->src, pe[i]->dst, pe[i]->w);*/
    for (i = 0; i < E && sc > 0; i++)
    {
        if ((p_src = SET(pe[i]->src)) != (p_dst = SET(pe[i]->dst)))
        {
            FAST_UNION(p_src, p_dst);

            if (sc == (S-1))
            {
                printf("%.2lf\n", sqrt(pe[i]->w));
                break; /* DONE */
            }
        }
    }

    return sc == 0;
}

int main()
{
    int i, j;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &S, &P);
        for (i = 0; i < P; i++)
        {
            scanf("%d %d", &c[i].x, &c[i].y);
        }

        E = 0;
        for (i = 0; i < P; i++)
            for (j = i+1; j < P; j++)
            {
                e[E].src = i;
                e[E].dst = j;
                e[E].w= POW2(c[i].x - c[j].x) + POW2(c[i].y - c[j].y);
                pe[E] = &e[E];
                E++;
            }


        INIT_SET(i);
        qsort(pe, E, sizeof(pe[0]), cmp);

        /* In this problem, there are always soultions */
        kruskal();
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

