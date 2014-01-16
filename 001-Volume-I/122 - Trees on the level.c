/****
 * 122 - Trees on the level
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int set;
    int value;
} node;

#define MAX_NODE  65536
const int root = MAX_NODE/2;
node nodes[MAX_NODE];
int node_num;

char buf[1000];

int test(int base, int shift)
{
    int l, r;

    if (shift == 0 || nodes[base].set == 0)
        return 0;

    l = test(base-shift, shift >> 1);

    if (l == -1)
        return -1;

    r = test(base+shift, shift >> 1);

    if (r == -1 || (nodes[base].set == 0 && (l != -1 || r != -1)))
        return -1;

    return 1 + l + r;
}

int main()
{
    int done, error, clear;
    int base, shift;
    int i, n;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (done = 0, clear = 0;;)
    {
        node_num = 0;
        error    = 0;
        if (clear == 0)
        {
            for (i = 0; i < MAX_NODE; i++)
                nodes[i].set = 0;
        }
        clear = 0;


        for (;;)
        {
            if (scanf("%s", buf) == EOF)
            {
                done = 1;
                break;
            }

            if (buf[0] == '(' && buf[1] == ')')
                break;

            if (error == 0)
            {
                node_num += 1;
                n = atoi(buf+1);

                for (i = 1; buf[i] != ','; i+=1);

                if (i == 1)
                {
                    error = 1;
                    continue;
                }
                i += 1;


                base  = root;
                shift = root >> 1;
                for (; buf[i] != ')'; i++)
                {
                    if (buf[i] == 'L')
                        base -= shift;
                    else
                        base += shift;

                    shift >>= 1;
                }

               /* printf("%s ", buf);
                printf("n = %d\n", n);*/

                if (nodes[base].set == 1)
                    error = 1;

                nodes[base].set = 1;
                nodes[base].value = n;
            }
        }

        if (done)
            break;

        if (error == 1 || node_num == 0)
        {
            puts("not complete");
            continue;
        }

        n = test(root, root>>1);
        if (n != node_num)
        {
            puts("not complete");
            continue;
        }

        printf("%d", nodes[root].value);
        nodes[root].set = 0;
        n--;

        for (shift = root>>1; n > 0; shift >>= 1)
            for (i = shift; i < MAX_NODE; i += shift)
                if (nodes[i].set == 1)
                {
                    printf(" %d", nodes[i].value);
                    nodes[i].set = 0;
                    n--;
                }
        printf("\n");
        clear = 1;
     }

#ifndef ONLINE_JUDGE
    /*system("pause");*/
#endif
    return 0;
}


