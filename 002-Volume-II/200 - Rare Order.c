/****
 * 200 - Rare Order
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 26
#define LEN 40

struct V
{
    int c;
    int e[MAX];
    int map[MAX];
    int u;
    int r;
};

struct V V[MAX];
#define ADD_EDGE(v0, _i_)   V[(v0)].e[V[(v0)].c++] = _i_;
#define GET_EDGE(v0, _i_)   (V[(v0)].e[(_i_)])
#define EDGE_NUM(v0)        (V[(v0)].c)
#define USED(v0)            (V[(v0)].u)
#define SET_USED(v0)        V[(v0)].u = 1;
#define CLEAR_USED(v0)      V[(v0)].u = 0;
#define REF(v0)             (V[(v0)].r)
#define INC_REF(v0)         V[(v0)].r += 1;
#define DEC_REF(v0)         V[(v0)].r -= 1;
#define MAP(v0, _i_)        (V[(v0)].map[_i_])
#define SET_MAP(v0, _i_)    MAP(v0, _i_) = 1;
#define IS_MAPPED(v0, _i_)  (MAP(v0, _i_) == 1)


int _S[MAX];
int _ST = 0;
#define ST_PUSH(v0)        _S[_ST++] = (v0);
#define ST_POP()          (_S[--_ST])
#define ST_IS_EMPTY()     (_ST == 0)

int main()
{
    char *p0, *p1, *pt;
    char buf0[LEN] , buf1[LEN];
    int i, j, edge;
    int s, d;

    p0 = buf0;
    p1 = buf1;
    p0[0] = '\n';

    for (i = 0; i < 26; i+=1)
    {
        USED(i) = REF(i) = EDGE_NUM(i) = 0;
    }
    for (i = 0; i < 26; i+=1)
        for (j = 0; j < 26; j+=1)
            MAP(i,j) = 0;

    for(;;)
    {
        fgets(p1, LEN, stdin);
        if (p1[0] =='#')
            break;

        i = 0;
        while (p0[i] != '\n' && p1[i] != '\n' && p0[i] == p1[i])
            i++;

        if (p0[i] != '\n' && p1[i] != '\n' && p0[i] != p1[i])
        {
            s = p0[i] - 'A';
            d = p1[i] - 'A';

            if (!IS_MAPPED(s, d))
            {
                SET_MAP(s, d);
                ADD_EDGE(s, d);
                SET_USED(s);
                SET_USED(d);
                INC_REF(d);
            }
        }

        /* SWAP */
        pt = p0;
        p0 = p1;
        p1 = pt;
    }

    for (i = 0; i < 26; i+=1)
        if (USED(i) == 1 && REF(i) == 0)
        {
            ST_PUSH(i);
            break;
        }

    while(!ST_IS_EMPTY())
    {
        i = ST_POP();
        if (USED(i) == 1)
        {
            printf("%c", i+'A');
            CLEAR_USED(i);

            for(j = 0; j < EDGE_NUM(i); j++)
            {
                edge = GET_EDGE(i, j);
                DEC_REF(edge);
                if (REF(edge) == 0)
                    ST_PUSH(edge);
            }
        }
    }
    printf("\n");

#ifndef ONLINE_JUDGE
    system("pause");
#endif

    return 0;
}
