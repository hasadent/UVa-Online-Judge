/****
 * 913 - Joana and the Odd Numbers
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n, x;

    while (scanf("%lld", &n) != EOF)
    {
        x = n + 1;
        x = x * x;
        x = x / 2 * 3 - 9;
        printf("%lld\n", x);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

