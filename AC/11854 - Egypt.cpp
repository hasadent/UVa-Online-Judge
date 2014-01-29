/****
 * 11854 - Egypt
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, b, c;
    for (;;)
    {
        cin >> a >> b >> c;

        if (a+b+c == 0)
            break;

        a *= a;
        b *= b;
        c *= c;

        if (a + b == c || a + c  == b || b + c == a)
            cout << "right\n";
        else
            cout << "wrong\n";

    }
    return 0;
}
