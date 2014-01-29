/****
 * 10165 - Stone Game
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

    int n;
    const char * out[2] = {"No\n", "Yes\n" };

    for (;;)
    {
        cin >> n;
        if (n == 0) break;

        int s = 0, x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            s ^=  x;
        }

        cout << out[s != 0];

    }

    return 0;
}
