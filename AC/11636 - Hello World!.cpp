/****
 * 11636 - Hello World!
 */
#include <iostream>
#include <iomanip>
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
    for (int x = 1;; x++)
    {
        cin >> n;
        if (n < 0) break;

        int s = 0;
        if (n != 0)
        {
            n--;
            while (n != 0)
            {
                n >>= 1;
                s++;
            }
        }

        cout << "Case " << x << ": " << (s) << endl;
    }

    return 0;
}
