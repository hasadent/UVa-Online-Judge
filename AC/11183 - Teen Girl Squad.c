/****
 * 11183 - Teen Girl Squad
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000
#define MAX_M 40000

struct edge{
    int s;
    int d;
    int w;
};
struct edge e[MAX_M];

#define VISITED_SIZE MAX_N
int _visited_key = 1;
int _visited[VISITED_SIZE];
#define INIT_VISITED(_i_) for (_i_ = 0; _i_ < VISITED_SIZE; _i_+=1) { _visited[_i_] = 0; }
#define RESET_VISITED()   _visited_key ++;
#define SET_VISITED(v0)   _visited[(v0)] = _visited_key;
#define IS_VISITED(v0)    (_visited[(v0)] == _visited_key)

int N, n, m;

int directed_MST(int root)
{
    int i, j, k;
    int has_cycle;
    int weight, weight_contracted = 0;

    int in_edge_weight[MAX_N];
    int in_edge_src[MAX_N];
    int v_in_cycle[MAX_N];
    int contracted[MAX_N];

    memset(contracted, 0, sizeof(contracted));
    for (;;)
    {
        for (i = 0; i < n; i++)
        {
            in_edge_weight[i] = 0x7fffffff;
            in_edge_src[i] = -1;
        }

        /* STEP 1 */
        for (i = 0; i < m; i++)
        {
            /* The edges should be ingored, but condition 1 & 2 are removed in the other place */
            /* 1. no edge to itself: e[i].s != e[i].d  */
            /* 2. no edge to root:   e[i].d != root    */
            /* 3. has the lowest weight in all in-edge */ 
            if (e[i].w < in_edge_weight[e[i].d])
            {
                in_edge_src[e[i].d] = e[i].s;
                in_edge_weight[e[i].d] = e[i].w;
            }
        }

        /* STEP 2 */
        weight = 0;
        has_cycle = 0;


        for (i = 0; i < n; i++)
        {
            if (contracted[i] == 1)
                continue;

            if (in_edge_src[i] == -1 && i != root)
            {
                return -1; /* no MST */
            }

            if (in_edge_src[i] != -1)
            weight += in_edge_weight[i];

            /* if three is a cycle in the graph and v[i] is one of vertex connected to the cycle,
                  the final j won't be -1. */
            RESET_VISITED();
            for (j = i;
                j != -1 && !IS_VISITED(j);
                j = in_edge_src[j])
                {
                    SET_VISITED(j);
                }

            if (j != -1 && IS_VISITED(j))
            {
                has_cycle = 1;
                for (k = 0; k < n; k++)
                    v_in_cycle[k] = -1;

                v_in_cycle[j] = j;
                weight_contracted += in_edge_weight[j];
                for (k = in_edge_src[j]; k != j; k = in_edge_src[k])
                {
                    v_in_cycle[k] = j;
                    contracted[k] = 1;
                    weight_contracted += in_edge_weight[k];
                }
                break;
            }
        }

        if (has_cycle == 0)
        {
            break;
        }

        /*  STEP 3:
           all vertexs in the cycle are contracted in to one vertex
             For an edge e not in the cycle: the new weight will be updated to 'e.w - in_edge_weight[e.d]'.
             It means if the edge is add to the MST, the edge from in_edge_src[e.d] to e.d would be removed.
        */
        for (i = 0; i < m ; i++)
        {
            if (v_in_cycle[e[i].d] >= 0)
            {
                e[i].w -= in_edge_weight[e[i].d];
                e[i].d = v_in_cycle[e[i].d];
            }

            if (v_in_cycle[e[i].s] >= 0)
            {
                e[i].s = v_in_cycle[e[i].s];
            }

            /* an edge to itself would be removed */
            if (e[i].s == e[i].d)
            {
                e[i--] = e[--m];
            }
        }
    }

    return weight + weight_contracted;
}


int main()
{

    int i, k = 0;
    int cost;

    INIT_VISITED(i);

    scanf("%d", &N);
    while ( k++ < N)
    {
        scanf("%d", &n);
        scanf("%d", &m);

        for (i = 0; i < m; i++)
        {
            scanf("%d %d %d", &e[i].s, &e[i].d, &e[i].w);

            /* remove a edge to itself*/
            if (e[i].s == e[i].d) {i--; m--;}

            /* remove a edge to root */
            if (e[i].d == 0) {i--; m--;}
        }

        cost = directed_MST(0);

        if (cost == -1)
        {
            printf("Case #%d: Possums!\n", k);
        }
        else
        {
            printf("Case #%d: %d\n", k, cost);
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

