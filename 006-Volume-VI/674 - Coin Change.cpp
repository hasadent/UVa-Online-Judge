/****
 * 674 - Coin Change
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int c[7490];
int x[5] = {1, 5, 10, 25, 50};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (int j = 0; j < 7490; j++)
        c[j] = 1;

    for (int i = 1; i < 5; i++)
        for (int j = x[i]; j < 7490; j++)
            c[j] += c[j-x[i]];

    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", c[n]);
    }
    return 0;
}
