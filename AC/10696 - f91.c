/****
 * 10696 - f91
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;

    while (scanf("%d", &N) != EOF && N != 0)
    {
        if (N > 100)
            printf("f91(%d) = %d\n", N, N-10);
        else
            printf("f91(%d) = %d\n", N, 91);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

