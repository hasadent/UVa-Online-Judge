/****
 * 440 - Eeny Meeny Moo
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int josephus(int n, int m)
{
    int r = 0;
    for (int i = 1; i <= n; i++)
        r = (r + m) % i;
    return r;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    for (;;)
    {
        cin >> n;

        if (n == 0)
            break;

        // city 1 (index 0) is  the first city to remove,
        // remove the city, so city 2 becomes the head of citys
        int k = 1;
        while (josephus(n-1, k) != 0) k++;
        cout << k << endl;
    }
    return 0;
}
