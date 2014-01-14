/****
 * 112 - Tree Summing
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int parent;
	int left;
	int right;

	int set;
	int value;
} node;

node nodes[2000];
#define INIT_NODE(_n)    { \
    nodes[_n].parent = nodes[_n].left = nodes[_n].right = -1;\
    nodes[_n].set = 0;   } \

char * buf, _buf[2048];
#define NEXT_CHAR(_c)   \
{                       \
    if (*buf == 0)      \
    {                   \
        buf = _buf;     \
        fgets(_buf, sizeof(_buf), stdin);  \
    }                   \
    _c = *buf ++;       \
}
#define IS_NUM(_c)      ('0' <= (_c) && (_c) <= '9')

int n;

int DFS(int i, int sum)
{
	if (i == -1 || nodes[i].set == 0)
		return 0;

	if (nodes[i].left == -1 && nodes[i].right == -1)
        return (sum + nodes[i].value) == n;

	if (DFS(nodes[i].left, sum + nodes[i].value) == 1)
        return 1;

    if (DFS(nodes[i].right, sum + nodes[i].value) == 1)
        return 1;

    return 0;
}

const char *output[2] = {"no", "yes"};

int main()
{
	int c;
	int done;
	int num, num_scanned, minus_scanned;
	int p_count; /* parentheses count*/
	int cn, parent;
	int node_id = 0;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

	while (scanf("%d", &n) != EOF)
	{
		/* reset input buffer */
		buf     = _buf;
		_buf[0] = 0;

        /* reset flags and counters */
		done          = 0;
		p_count       = 0;
        num           = 0;
		num_scanned   = 0;
		minus_scanned = 0;

		/* reset tree nodes */
		cn =  node_id = 0;
		INIT_NODE(0);

		while (!done)
		{
			NEXT_CHAR(c);

			if (IS_NUM(c))
			{
				num = num * 10 + c - '0';
				num_scanned = 1;
			}
			else
			{
			    if (c == '(' || c == ')' || c == '-')
			    {
                    if (num_scanned == 1)
                    {
                        /*printf("END_NUM_SCAN: num = %d to node %d\n", num, cn);*/
                        if (minus_scanned)
                            num = -num;

                        nodes[cn].value = num;
                        nodes[cn].set   = 1;

                        /* reset relative flags and counters */
                        num           = 0;
                        num_scanned   = 0;
                        minus_scanned = 0;
                    }


                    if (c == '(')
                    {
                        p_count += 1;

                        /* new node */
                        node_id += 1;
                        INIT_NODE(node_id);
                        nodes[node_id].parent = cn;

                        /* set the new node as a sub node of the currenet node */
                        if (nodes[cn].left == -1)
                            nodes[cn].left  = node_id;
                        else if (nodes[cn].right == -1)
                            nodes[cn].right = node_id;
                        else{
                            printf("%d", cn);
                            return 1; /*make RE */
                        }

                        cn = node_id;
                    }
                    else if (c == ')')
                    {
                        p_count -= 1;

                        /* remove empty node */
                        if (nodes[cn].set == 0)
                        {
                            parent = nodes[cn].parent;

                            if (cn == nodes[parent].left)
                                nodes[parent].left = -1;
                            else
                                nodes[parent].right = -1;
                        }
                        cn = nodes[cn].parent;


                        if (p_count == 0)
                            done = 1;
                    }
                    else if (c == '-')
                    {
                        minus_scanned = 1;
                    }
			    }
			}
		} /* while !done*/

		printf("%s\n", output[DFS(1, 0)]);
	}

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;

}
