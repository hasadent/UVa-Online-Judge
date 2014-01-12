/****
 * 101 - The Blocks Problem
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_B 25

#define MOVE 1
#define PILE 0
#define ONTO 1
#define OVER 0

struct pos_info{
    int c;
    int b[MAX_B];
};


struct pos_info info[MAX_B];
#define ADD(_p,_b)  { info[_p].b[info[_p].c++] = _b;  pos[_b] = _p; }
int             pos[MAX_B];

void put(int b1, int b2)
{
    int p1 = pos[b1];
    int p2 = pos[b2];
    ADD(p1, b2);
    info[p2].c--;
}

void restore_over(int b1)
{
    int p1 = pos[b1];
    int i;
    for (i = info[p1].c - 1; info[p1].b[i] != b1; i--)
        ADD(info[p1].b[i], info[p1].b[i]);
    info[p1].c = i + 1;
}

void put_all(int b1, int b2)
{
    int p1 = pos[b1];
    int p2 = pos[b2];
    int i, j;

    if (p1 == p2)
        return;

    for (i = 0; i < info[p2].c; i++)
        if (info[p2].b[i] == b2)
            break;
    j = i;
    for (; i < info[p2].c; i++)
    {
        ADD(p1, info[p2].b[i])
    }
    info[p2].c = j;
}

int main()
{
    int n;
    int a, b, cmd, func, step;
    int i, j;
    char buf[100], *c;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d\n", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            info[i].c = 1;
            info[i].b[0] = i;
            pos[i] = i;
        }

        for (step = 0;; step++)
        {
            /* input */
            c = buf; gets(c);

            if (c[0] == 'q') break;

            cmd = c[0] == 'm' ? MOVE : PILE;

            a = c[5] - '0';
            if (c[6] != ' ')
            {
                a = a*10 + c[6] - '0';
                c += 8;
            }
            else
            {
                c += 7;
            }

            func = c[1] == 'n' ? ONTO : OVER;
            b = c[5] - '0';
            if (c[6] != 0)
            {
                b = b*10 + c[6] - '0';
            }


            /* motion */
            if (step < 4 && a == b)
                continue;

            if (pos[a] == pos[b])
                continue;

            if (cmd == MOVE)
            {
                if (func == ONTO)
                    restore_over(b);

                restore_over(a);
                put(b, a);
            }
            else if (cmd == PILE)
            {
                if (func == ONTO)
                    restore_over(b);

                put_all(b, a);
            }
        }

        /* output */
        for (i = 0; i < n; i++)
        {
            printf("%d:", i);
            for (j = 0; j < info[i].c; j++)
                printf(" %d", info[i].b[j]);
            printf("\n");
        }

    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
