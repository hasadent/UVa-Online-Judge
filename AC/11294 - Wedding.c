#include <stdio.h>
#include <stdlib.h>

#define MAX_N 30
#define ADD_EDGE(v0, v1) { v[(v0)].e[v[(v0)].c] = (v1); v[(v0)].c ++; }

struct v{
    int c;
    int e[MAX_N * 2];
    int tf;
};

struct v v[MAX_N*2];
int n;


#define ST_SIZE         MAX_N*2
int _S[ST_SIZE];
int _ST = 0;
#define ST_RESET()      _ST = 0;
#define ST_PUSH(v0)     _S[_ST++] = (v0);
#define ST_POP(v0)      v0 = _S[--_ST];
#define ST_TOP()        (_S[_ST-1])
#define ST_IS_EMPTY()   (_ST == 0)

int dfs(int x)
{
    int i;
    if (v[x^1].tf != 0) return 0;
    if (v[x].tf != 0) return 1;

    ST_PUSH(x);
    v[x].tf = 1;

    for (i = 0; i < v[x].c; i+=1)
    {
        if (dfs(v[x].e[i]) == 0)
            return 0;
    }
    return 1;
}

int solve()
{
    int i, j;

    for (i = 0; i < n*2; i+=2)
    {
        if (v[i].tf == 0 && v[i^1].tf == 0)
        {
            ST_RESET();
            if(dfs(i) == 0)
            {
                /* restore previos dfs */
                while (!ST_IS_EMPTY()) {
                    ST_POP(j);
                    v[j].tf = 0;
                }
                /* try another path */
                if(dfs(i^1) == 0)
                    return 0;
            }
        }
    }
    return 1;
}

int ascii[256];

int main()
{
    int ap;
    int x[2];
    char y[2];
    int i;
    ascii['w'] = 1;
    ascii['h'] = 0;

    while (scanf("%d %d", &n, &ap) != EOF)
    {
        if (n == 0 && ap == 0) break;

        for (i = 0; i < n*2; i++)
        {
            v[i].c = 0;
            v[i].tf = 0;
        }

        for (i = 0; i < ap; i++)
        {
            scanf("%d%c %d%c", x, y, x+1, y+1);
            x[0] = (x[0] << 1) + ascii[y[0]];
            x[1] = (x[1] << 1) + ascii[y[1]];

            ADD_EDGE(x[0]^1, x[1]);
            ADD_EDGE(x[1]^1, x[0]);
        }
        ADD_EDGE(0,1);

        if (solve() == 0)
        {
            puts("bad luck");
        }
        else
        {
            for (i = 2; i < n*2;  i+=2)
            {
                if(i != 2) printf(" ");

                if(v[i].tf == v[0].tf)
                    printf("%dw", i/2);
                else
                    printf("%dh", i/2);
            }
            puts("");
        }
    }/* while */

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

