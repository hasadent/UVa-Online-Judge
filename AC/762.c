/****
 * 762 - We Ship Cheap
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 26*26

struct V
{
    int e[MAX];
    int c;
    int p;
};
struct V v[MAX];
#define ADD_EDGE(v0, v1)   v[(v0)].e[v[(v0)].c++] = v1;
#define EDGE_NUM(v0)       v[(v0)].c
#define EDGE(v0, _i_)      v[(v0)].e[(_i_)]
#define PARENT(v0)         v[(v0)].p

#define RESET_VISITED() visited_key ++;
int visited_key = 1;
int visited[MAX];

int _Q[MAX*10];
int _QF = 0, _QR = 0;
#define Q_RESET()       _QF = _QR = 0;
#define Q_ENQUEUE(v0)   _Q[_QR++] = (v0);
#define Q_DEQUEUE()     _Q[_QF++]
#define Q_IS_EMPTY()    (_QF == _QR)

int _S[MAX];
int _ST = 0;
#define ST_RESET()         _ST = 0;
#define ST_PUSH(v0)        _S[_ST++] = (v0);
#define ST_POP()          (_S[--_ST])
#define ST_TOP()          (_S[_ST-1])
#define ST_IS_EMPTY()     (_ST == 0)

#define P(v)

int main()
{
    int N;
    char buf[20];
    int id0, id1;
    int i, j, d, edge, find;
    int f = 0;

    for (i = 0; i < 676; i++)
        visited[i] = 0;

    while (scanf("%d\n", &N) != EOF)
    {
        Q_RESET();
        ST_RESET();
        RESET_VISITED();

        for (i = 0; i < 676; i+= 1)
        {
            EDGE_NUM(i) = 0;
        }

        for (i = 0; i < N + 1; i += 1)
        {
            fgets(buf, 20, stdin);

            id0 = (buf[0]-'A') * 26 + (buf[1]-'A');
            id1 = (buf[3]-'A') * 26 + (buf[4]-'A');

            if (i != N)
            {
                ADD_EDGE(id0, id1);
                ADD_EDGE(id1, id0);
            }
            else
            {
                Q_ENQUEUE(id0);
                find = 0;

                while (!Q_IS_EMPTY())
                {
                    d = Q_DEQUEUE();
                    visited[d] = visited_key;
                    for (j = 0; j < EDGE_NUM(d); j+= 1)
                    {
                        edge = EDGE(d, j);
                        if (visited[edge] != visited_key)
                        {
                            PARENT(edge) = d;
                            if (edge == id1)
                            {
                                find = 1;
                                break;
                            }
                            Q_ENQUEUE(edge);
                        }
                    }

                    if (find == 1)
                        break;
                }

                if (f == 1)
                    putc('\n', stdout);
                f = 1;

                if (find == 1)
                {
                    while (edge != id0)
                    {
                        ST_PUSH(edge);
                        edge = PARENT(edge);
                    }

                    while (!ST_IS_EMPTY())
                    {
                        putc(edge / 26 + 'A', stdout);
                        putc(edge % 26 + 'A', stdout);
                        putc(' ', stdout);
                        edge = ST_POP();
                        putc(edge / 26 + 'A', stdout);
                        putc(edge % 26 + 'A', stdout);
                        putc('\n', stdout);
                    }
                }
                else
                {
                    puts("No route");
                }
            } /* if (find = 1) */
        } /* for */

        if (fgets(buf, 20, stdin) == NULL)
            break;
    } /* while */

    return 0;
}
