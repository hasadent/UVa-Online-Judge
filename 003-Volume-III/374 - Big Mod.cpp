/****
 * 374 - Big Mod
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int mod(int b, int p, int m)
{
    if (p == 0)
        return 1;

    if (p == 1)
        return b % m;

    if ((p&1) == 0)
        return mod((b*b)%m, p/2, m);

    return (b * mod((b*b)%m, p/2, m)) % m;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int b, p, m;
    while (cin >> b >> p >> m)
    {
        if (p == 0)
        {
            b = 1;
        }

        b %= m;

        cout << mod(b, p ,m) << endl;
    }

    return 0;
}
