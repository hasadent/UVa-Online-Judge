/****
 * 10970 - Big Chocolate
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

    int n, m;
    while (cin >> n >> m)
    {
        cout << n * m - 1 << '\n';
    }
    return 0;
}
