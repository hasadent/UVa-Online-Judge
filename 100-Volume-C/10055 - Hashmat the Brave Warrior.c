/****
 * 10055 - Hashmat the Brave Warrior
 */
#include <stdio.h>
#include <stdlib.h>


int main()
{
    long long a, b;


#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%u %u", &a, &b) != EOF)
    {
        printf("%u\n", a > b ? a - b : b - a);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
