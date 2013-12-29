/****
 * 10410 - Tree Reconstruction
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

struct T
{
    int s[MAX-2];
    int c;
};

int N;
int bfs[MAX];
int dfs[MAX];
int bfs_i[MAX];
int dfs_i[MAX];
struct T t[MAX];

/* Find index of a value in DFS */
#define BFSV_DFSI(bfs_v)  dfs_i[(bfs_v)]
/* Find index of a value in BFS */
#define DFSV_BFSI(dfs_v)  bfs_i[(dfs_v)]
#define ADD_NODE(v0, v1)  t[(v0)].s[t[(v0)].c++] = (v1);

void  reconstruct(int dfs_s, int dfs_e)
{
    int root;
    int sub_s, sub_e;
    int p;

    /*printf("root = %d, dfs:%d->%d\n", dfs[dfs_s], dfs_s, dfs_e);*/
    if (dfs_s + 1 == dfs_e)
        return;

    root = dfs[dfs_s++];
    p = DFSV_BFSI(dfs[dfs_s]);

    sub_s = 0;
    sub_e = BFSV_DFSI(bfs[p]);
    ADD_NODE(root, bfs[p]);
    p++;

    for (;;)
    {
        sub_s = sub_e;
        sub_e = BFSV_DFSI(bfs[p]);

        if (sub_s > sub_e || sub_e < dfs_s || sub_e >= dfs_e || p >= N)
            break;
        ADD_NODE(root, bfs[p]);
        p++;

        /*printf("root = %d, %d <-> %d\n", root, sub_s, sub_e);*/
        reconstruct(sub_s, sub_e);
    }

    sub_e = dfs_e;
    /*printf("root = %d, %d <-> %d\n", root, sub_s, sub_e);*/
    reconstruct(sub_s, sub_e);
}


int main()
{
    int i, j;

    while (scanf("%d", &N) != EOF)
    {
        for (i = 0; i < N; i+=1)
        {
            t[i].c = 0;
            scanf("%d", bfs+i);
            bfs_i[bfs[i]] = i;
        }
        t[i].c = 0;

        for (i = 0; i < N; i+=1)
        {
            scanf("%d", dfs+i);;
            dfs_i[dfs[i]] = i;
        }

        reconstruct(0, N);

        for (i = 1; i <= N; i++)
        {
            printf("%d:", i);
            for (j = 0; j < t[i].c; j+=1)
                printf(" %d", t[i].s[j]);
            printf("\n");
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

