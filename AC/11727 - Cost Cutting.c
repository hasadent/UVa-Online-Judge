/****
 * 11727 - Cost Cutting
 */
#include <stdio.h>
#define MAX2(_a, _b)     (_a > _b ? _a : _b)
#define MAX3(_a, _b, _c) MAX2(_a, MAX2(_b, _c))
#define MIN2(_a, _b)     (_a < _b ? _a : _b)
#define MIN3(_a, _b, _c) MIN2(_a, MIN2(_b, _c))

int main()
{
    int t, i;
    int a,b,c;

    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: %d\n", i, a + b + c - MAX3(a,b,c) - MIN3(a,b,c));
    }

    return 0;
}
