/****
 * 568 - Just the Facts
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int r[10001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    r[1] = 1;
    for (int i = 2; i <= 10000; i++)
    {
        for (r[i] = r[i-1] * i; r[i] % 10 == 0; r[i] /= 10);
        r[i] %= 100000;
    }

    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%5d -> %d\n", n, r[n] % 10);
    }

    return 0;
}
