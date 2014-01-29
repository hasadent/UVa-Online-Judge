/****
 * 10127 - Ones
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
    while (cin >> n)
    {
        int i = 0;
        int k = 0;

        do
        {
            k = k * 10 + 1;
            i++;

            k %= n;
        }
        while (k != 0);

        cout << i << endl;

    }
    return 0;
}
