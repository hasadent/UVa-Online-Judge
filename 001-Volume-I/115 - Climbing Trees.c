/****
 * 115 - Climbing Trees
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_PERSON   300
#define MAX_NAME      32

int parent[MAX_PERSON];
int n = 0;
char namelist[MAX_PERSON][MAX_NAME];
#define FIND_NAME(_name, _i)                  \
{                                             \
    for (_i = n-1; _i >= 0; _i -= 1)          \
        if (strcmp(namelist[_i], _name) == 0) \
            break;                            \
}
#define ADD_NAME(_name, _n)  { _n = n++; strcpy(namelist[_n], _name); }

int stack_a[MAX_PERSON];
int a;
int stack_b[MAX_PERSON];
int b;

int main()
{
    char name_1[MAX_NAME], name_2[MAX_NAME];
    int i, j;
    int x, y;
    int p, q;
    int par;
    int done;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    memset(parent, -1, sizeof(parent));
    n = 0;
    while (scanf("%s %s\n", name_1, name_2) != EOF)
    {
        if (strcmp(name_1, "no.child") == 0)
            break;

        FIND_NAME(name_1, x);
        if (x == -1)
            ADD_NAME(name_1, x);

        FIND_NAME(name_2, y);
        if (y == -1)
            ADD_NAME(name_2, y);

        parent[x] = y;
    }

    while (scanf("%s %s\n", name_1, name_2) != EOF)
    {
        FIND_NAME(name_1, p);
        if (p == -1)
        {
            puts("no relation");
            continue;
        }
        
        FIND_NAME(name_2, q);
        if (q == -1)
        {
            puts("no relation");
            continue;
        }

        /* relation 1 */
        par = parent[p];
        a = 0;
        while (par != -1 && par != q)
        {
            stack_a[a++] = par;
            par = parent[par];
        }

        if (par != -1)
        {
            while (a > 1)
            {
                printf("great ");
                a --;
            }
            if (a == 1)
                printf("grand ");
            puts("child");
            continue;
        }

        /* relation 2 */
        par = parent[q];
        b = 0;
        while (par != -1 && par != p)
        {
            stack_b[b++] = par;
            par = parent[par];
        }

        if (par != -1)
        {
            while (b> 1)
            { printf("great "); b--; }
            if (b == 1)
                printf("grand ");
            puts("parent");
            continue;
        }

        /* relation 3 & 4 */
        done = 0;
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < b; j++)
                if (stack_a[i] == stack_b[j])
                {
                    done = 1;
                    break;
                }
            if (done)
                break;
        }

        if (i == a && j == b)
        {
            puts("no relation");
            continue;
        }

        if (i == 0 && j == 0)
        {
            puts("sibling");
            continue;
        }

        if (i == j)
        {
            printf("%d cousin\n", i);
            continue;
        }

        if (i > j)
        {
            x = j;
            y = i - j;
        }
        else
        {
            x = i;
            y = j - i;
        }

        printf("%d cousin removed %d\n", x, y);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
