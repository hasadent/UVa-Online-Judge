/****
 * 264 - Count on Cantor
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    while (scanf("%d", &n) != EOF)
    {
        int m = 0, lv = 1;
        while (m+lv < n)
        {
            m  += lv;
            lv += 1;
        }

        //cout << "n = " << n << ", lv = " << lv << ", m = " << m << endl;

        int a, b;

        if ((lv & 1) == 0)
        {
            a = n - m;
            b = lv - n + m + 1;
        }
        else
        {
            a = lv - n + m + 1;
            b = n - m;
        }

        printf("TERM %d IS %d/%d\n", n, a, b);
    }

    return 0;
}
