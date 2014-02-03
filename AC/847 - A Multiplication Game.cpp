/****
 * 847 - A Multiplication Game
 */
#include <iostream>
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


    int n;
    while (scanf("%d", &n) != EOF)
    {
        int p = 1;

        int ub = 18;
        int lb = 10;

        while (n > ub)
        {
            ub *= 18;
            lb = ub / 2 + 1;
        }

        if (n >= lb)
            puts("Ollie wins.");
        else
            puts("Stan wins.");

    }
    return 0;
}
