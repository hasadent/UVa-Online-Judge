/****
 * 10062 - Tell me the frequencies!
 */
#include <stdio.h>
#include <stdlib.h>

#define IGNORE_ASCII 32
#define MAX_ITEM     129 - IGNORE_ASCII

struct i{
    int ascii;
    int count;
};

struct i items[MAX_ITEM];
struct i * ix = items - IGNORE_ASCII;
char buf[1004], *p;

int cmp(const void * a, const void * b)
{
    struct i *x = (struct i *)a, *y = (struct i *)b;

    if (x->count == y->count)
        return y->ascii - x->ascii;
    return x->count - y->count;
}

int main()
{
    int i;
    int first = 0;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    while (gets(buf) != NULL)
    {
        for (i = 0; i < MAX_ITEM; i++)
        {
            items[i].ascii = IGNORE_ASCII+i;
            items[i].count = 0;
        }
        for (p = buf; *p != 0; p++)
            ix[*p].count +=1;

        qsort(items, sizeof(items)/sizeof(items[0]), sizeof(items[0]), cmp);

        for (i = 0; i < MAX_ITEM; i++)
            if (items[i].count != 0)
                break;

        if (first == 1)
            puts("");
        first = 1;

        for (; i < MAX_ITEM; i++)
        {
            printf("%d %d\n", items[i].ascii, items[i].count);
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
