/****
 * 10783: Odd Sum
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, a, b;
    int i, k;
    int os;

    scanf("%d", &t);
    for (i = 1; i <=t; i++)
    {
        scanf("%d %d", &a, &b);
        a = a | 1;
        b = b - ((b&1)^1);
        os = ((b+a) * (b-a+2)) >> 2;
        printf("Case %d: %d\n", i, os);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
