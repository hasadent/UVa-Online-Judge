/****
 * 10071 - Back to High School Physics
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v, t;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d %d", &v, &t) != EOF)
    {
        printf("%d\n", 2 * v * t);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
