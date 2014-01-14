/****
 * 113 - Power of Cryptography
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    double p;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    while(scanf("%d %lf", &n, &p) != EOF)
    {
        printf("%.0lf\n", pow(p, 1.0/n));
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
