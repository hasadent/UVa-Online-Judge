/****
 * 11044 - Searching for Nessy
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t, n, m;

    scanf("%d", &t);
    while (t-- > 0)
    {
        scanf("%d %d", &n, &m);
        n -= 2; m -= 2;
        int a = (n % 3 > 0 ? 1 : 0) + n / 3;
        int b = (m % 3 > 0 ? 1 : 0) + m / 3;
        printf("%d\n", a*b);
    }

    return 0;
}
