/****
 * 12442 - Forwarding Emails
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 50001

struct u{
    int v; /* mail target */
    int c; /* number of mail*/
};

struct u u[MAX]; /* Martains */
int mailed[MAX]; /* the walked Martains mark */
int key_mailed;  /* an unique key as a mark */
int stack[MAX];  /* stack of the pervious walked Martains*/
int sn = 0;      /* stack count */

#define INIT_MAILED()  memset(mailed, 0, sizeof(int)*MAX);
#define RESET_MAILED() key_mailed++;
#define COST(node)     (u[(node)].c)
#define NEXT(node)     (u[(node)].v)

#define RESET_STACK()  sn = 0;
#define PUSH(node)     stack[sn++] = (node);
#define POP()          (stack[--sn])
#define IS_EMPTY()     (sn == 0)
#define SIZE()         (sn)


void mail_start(int v)
{
    int cost, i, p;
    if (COST(v) != -1) return;

    RESET_MAILED();
    RESET_STACK();

    for(;;)
    {
        /* reach a calculated note */
        if (COST(v) != -1)
        {
            cost = COST(v);
            break;
        }

        /* case CYCLE */
        if (mailed[v] == key_mailed)
        {
            for (i = 0; stack[i] != v; i+=1);
            cost = SIZE() - i;

            while ((p = POP()) != v)
            {
                COST(p) = cost;
            }
            COST(p) = cost;

            break;
        }
        mailed[v] = key_mailed;
        PUSH(v);
        v = NEXT(v);
    }

    while (!IS_EMPTY())
    {
        p = POP();
        COST(p) = ++cost;
    }
}

int main()
{
    int t, n, iu, iv;
    int i, j, k;

    INIT_MAILED();

    scanf("%d", &t);
    for (i = 0; i < t; i+=1)
    {
        scanf("%d", &n);

        for (j = 0; j < n; j+=1)
        {
            scanf("%d %d", &iu, &iv);
            NEXT(iu) = iv;
            COST(iu) = -1;
        }

        for (j = 1; j <= n; j+=1)
            mail_start(j);

        /* find */
        k = 1;
        for (j = 2; j <= n; j+=1)
        {
            if (COST(k) < COST(j))
            {
                k = j;
            }
        }

        printf("Case %d: %d\n", i+1, k);
    }

    return 0;
}

