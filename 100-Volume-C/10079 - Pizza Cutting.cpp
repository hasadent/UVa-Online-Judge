/****
 * 10079 - Pizza Cutting
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    long long n;

    for (;;)
    {
        cin >> n;
        if (n < 0) break;

        cout << (1 + n) * n / 2 + 1 << "\n";
    }

    return 0;
}

