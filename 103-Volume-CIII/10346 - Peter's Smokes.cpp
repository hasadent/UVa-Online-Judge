/****
 * 10346 - Peter's Smokes
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

    int n, k;
    while (cin >> n >> k)
    {
        int s = 0;
        int b = 0;

        while (n != 0)
        {
            s += n;
            b += n;

            n = b / k;
            b = b % k;
        }
        cout << s << endl;
    }
    return 0;
}
