/****
 * 10696 - f91
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;

    scanf("%d", &N);
    while (N != 0)
    {
        if (N <= 100)
            printf("f91(%d) = 91\n", N);
        else
        {
            printf("f91(%d) = %d\n", N, N-10);
        }

        scanf("%d", &N);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

