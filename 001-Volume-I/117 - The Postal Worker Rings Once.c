/****
 * 117 - The Postal Worker Rings Once
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1000

int G[26][26]; 
int L[26]; /* edge number of each vertex */
int distance[26];
int visited[26];

void dijkstra(int src)
{
    int i, j, a, b, min;

    memset(visited, 0, sizeof(visited));
    for (i = 0; i < 26; i++)
        distance[i] = MAX_NUM;

    distance[src] = 0;
    for (i = 0; i < 26; i++)
    {
        a = -1; min = MAX_NUM;
        for (j = 0; j < 26; j++)
            if (visited[j] == 0 && distance[j] < min)
            {
                a = j;
                min = distance[j];
            }

        if (a == -1) break;
        visited[a] = 1;

        for (b = 0; b < 26; b++)
            if (visited[b] == 0 && distance[a] + G[a][b] < distance[b])
            {
                distance[b] = distance[a] + G[a][b];
            }
    }
}

int main()
{
    char buf[100];
    int done;
    int len, total_len;
    int i, j;
    int x, y;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (done = 0; ;)
    {
        for (i = 0; i < 26; i++)
            for (j = 0; j < 26; j++)
            G[i][j] = MAX_NUM;

        memset(L, 0, sizeof(L));

        total_len = 0;
        for (;;)
        {
            if (gets(buf) == 0)
            {
                /* program done */
                done = 1;
                break;
            }

            len = strlen(buf);
            
            /* input done */
            if (buf[0] == buf[len-1])
                break;

            x = buf[0] - 'a';
            y = buf[len-1] - 'a';

            if  (len < G[x][y])
            {
                G[x][y] = G[y][x] = len;
            }
            L[x] += 1;
            L[y] += 1;
            total_len += len;
        }

        if (done) break;

        /* find a vetex with an odd edge number */
        x = -1;
        for (i = 0; i <26; i++)
            if ((L[i] & 1) == 1)
            { x = i; break; }

        /* all verteces have even edges */
        if (x == -1)
        {
            printf("%d\n", total_len);
            continue;
        }

        for (i ++; i <26; i++)
            if ((L[i] & 1) == 1)
            { 
                y = i; 
                break; 
            }

        dijkstra(x);

        printf("%d\n", total_len + distance[y]);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
