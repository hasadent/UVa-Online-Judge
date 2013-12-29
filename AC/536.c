/****
 * 536 - Tree Recovery
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

char * preorder, *inorder, *postorder;
char buf[MAX*2], out[MAX];

void recover(char *s, char * e)
{
    char * s_t = s;
    char n;

    if (s > e)
    {
        return;
    }

    while (*s != *preorder) s++;
    n = *preorder++;
    recover(s_t, s-1);
    recover(s+1, e);
    *postorder ++ = n;

    return;
}

int main()
{
    int i;

    while (fgets(buf, MAX*2, stdin) != NULL)
    {
        for (i = 0; buf[i] != ' '; i+=1);

        preorder = buf;
        inorder = buf+i+1;
        postorder = out;

        recover(inorder, inorder+i-1);
        *postorder = 0;
        puts(out);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

