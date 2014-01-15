/****
 * 136 - Ugly Numbers
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1500
#define MIN2(a, b)    (a > b ? b : a)
#define MIN3(a, b, c)  MIN2(a, MIN2(b, c))

int UN[MAX_NUM];

int main()
{
    int mult_2, mult_3, mult_5;
    int i, j, k, l;
    int prev_un;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    UN[0] = prev_un = 1;
    j = k = l = 0;

    for (i = 1; i < MAX_NUM; i++)
    {
        for (; (mult_2 = UN[j] * 2) <= prev_un; j++);
        for (; (mult_3 = UN[k] * 3) <= prev_un; k++);
        for (; (mult_5 = UN[l] * 5) <= prev_un; l++);
        UN[i] = prev_un = MIN3(mult_2, mult_3, mult_5);
        /*printf("%d, %d, %d, %d\n", mult_2, mult_3, mult_5, UN[i]);*/
    }
    printf("The 1500'th ugly number is %d.\n", UN[MAX_NUM-1]);

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
