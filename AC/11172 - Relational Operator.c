/****
 * 11172 - Relational Operator
 */
#include <stdio.h>

int main()
{
    int n;
    int a, b;

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d %d", &a, &b);
        if (a == b)     puts("=");
        else if (a < b) puts("<");    
        else            puts(">");
    }


    return 0;

}
