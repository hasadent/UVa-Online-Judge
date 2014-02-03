/****
 * 694 - The Collatz Sequence
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

    long long int  A, L;
    for (int c = 1;; c++)
    {
        scanf("%lld %lld", &A, &L);
        if (A < 0) break;

        printf("Case %d: A = %lld, limit = %lld, ", c, A, L);

        int t = 1;
        while (A != 1)
        {
            if ((A & 1) == 1)
            {
                A = A * 3 + 1;
            }
            else
            {
                A /= 2;
            }

            if (A > L) break;

            t++;
        }


        printf("number of terms = %d\n", t);
    }
    return 0;
}
