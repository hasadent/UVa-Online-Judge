/****
 * 10212 - The Last Non-zero Digit.
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int s[4] = {6, 2, 4, 8};
const int odd[10][10] =
{
   { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 } , /* 0 */
   { -1,  1, -1,  3, -1, -1, -1,  7, -1,  9 } , /* 1 */
   { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 } , /* 2 */
   { -1,  3, -1,  9, -1, -1, -1,  1, -1,  7 } , /* 3 */
   { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 } , /* 4 */
   { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 } , /* 5 */
   { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 } , /* 6 */
   { -1,  7, -1,  1, -1, -1, -1,  9, -1,  3 } , /* 7 */
   { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 } , /* 8 */
   { -1,  9, -1,  7, -1, -1, -1,  3, -1,  1 } , /* 9 */
};
char f[20000001][3];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (int i = 1; i < 20000001; i++)
    {
        int k = i;
        f[i][1] = f[i][2] = 0;
        for (; k % 10 == 0; k /= 10);
        for (; k % 5 == 0; f[i][2]++, k /= 5);
        for (; k % 2 == 0; f[i][1]++, k /= 2);
        f[i][0] = k % 10;
    }

    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int n2 = 0, n5 = 0;

        int z = 1;
        for (int i = n; i >= n - m + 1; i--)
        {
#if 0
            /* SLOW */
            int k = i;
            for (; k % 10 == 0; k /= 10);
            for (; k % 5 == 0; n5++, k /= 5);
            for (; k % 2 == 0; n2++, k /= 2);
            z = odd[z][k%10];
#endif
            z = odd[z][f[i][0]];
            n2 += f[i][1];
            n5 += f[i][2];
        }

        if (n5 > n2)
        {
            puts("5");
            continue;
        }

        if (n2 > n5)
        {
            n2 -= n5;
            z = (z * s[n2 & 3]) % 10;
        }

        printf("%d\n", z);
    }

    return 0;
}
