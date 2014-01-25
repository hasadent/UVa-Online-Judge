/****
 * 10300 - Ecological Premium
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
    cin >> n;
    while (n-- > 0)
    {
        int f;
        cin >> f;

        int sum = 0;
        for (int x, y, z, i = 0; i < f; i++)
        {
            cin >> x >> y >> z;
            sum += x * z;

        }

        cout << sum << endl;
    }

    return 0;
}
