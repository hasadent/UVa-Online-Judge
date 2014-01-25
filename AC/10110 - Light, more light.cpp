/****
 * 10110 - Light, more light
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    const char * out[2] = { "no\n", "yes\n"};

    for (;;)
    {
        unsigned int n, s;

        cin >> n;

        if (n == 0)
            break;

        s = (unsigned int)sqrt(n);

        cout << out[s * s == n];
    }
    return 0;
}
