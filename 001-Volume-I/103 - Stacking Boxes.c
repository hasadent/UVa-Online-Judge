/****
 * 103 - Stacking Boxes
 */
#include <stdio.h>
#include <stdlib.h>

int n; /* number of boxes */
int d; /* dimension of boxes */
int b[30][11]; /* box list, b[?][0] -> box id, b[?][1-10] -> lines */
int *ob[30];   /* ordered box */

/* for sorting lines in abox*/
int cmp_int(const void * a, const void *b)
{
    return *(int*)a - *(int*)b;
}

/* for sorting boxes */
int cmp_intA(const void * a, const void *b)
{
    return *(((int**)b)[0]) - *(((int**)a)[0]);
}

int len[30];
int prev[30];

int can_put(int i_o, int i_i)
{
    int i;
    for (i = 0; i < d; i+=1)
    {
        if (ob[i_o][i] <= ob[i_i][i])
            return 0;
    }
    return 1;
}

int main()
{
    int i, j;
    int max_l, max_i;

    for (i = 0; i < 30; i++)
        b[i][0] = i+1;

    while (scanf("%d %d", &n, &d) != EOF)
    {
        for (i = 0; i < n; i+=1)
        {
            ob[i] = &b[i][1];

            for (j = 0; j < d; j+=1)
            {
                scanf("%d", &ob[i][j]);
            }
            qsort(ob[i], d, sizeof(int), cmp_int);
        }
        qsort(ob, n, sizeof(int*), cmp_intA);


        /* LIS init */
        for (i = 0; i < n; i+=1)
        {
            len[i] = 1;
            prev[i] = -1;
        }

        /* LIS */
        for (i = 0 ; i < n; i++)
            for (j = i+1; j < n; j++)
                if (can_put(i,j) & len[i]+1 > len[j])
                {
                    len[j] = len[i] + 1;
                    prev[j] = i;
                }

        /* find max len */
        max_i = 0;
        max_l = len[0];
        for (i = 1; i < n; i++)
            if (len[i] > max_l)
            {
                max_i = i;
                max_l = len[i];
            }
    
        /* output */
        printf("%d\n",max_l);
        i = max_i;
        while (prev[i] != -1)
        {
            printf("%d ", ob[i][-1]);
            i = prev[i];
        }
        printf("%d\n", ob[i][-1]);
    }
    
    return 0;
}
