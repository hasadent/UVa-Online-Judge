/****
 * 11727 - Cost Cutting
 */
#include <stdio.h>

int main()
{
    int t;
    int a, b, c;

    scanf("%d", &t);
    while (t-- > 0)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a > b) 
            printf("%d\n", b > c ? b : c);
        else
            printf("%d\n", a > c ? a : c);        
    }


    return 0;

}
