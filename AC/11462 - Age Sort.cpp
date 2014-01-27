/****
 * 11462 - Age Sort
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


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



        vector<int> v;
        while(n-- > 0)
        {
            int x;
            cin >>x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        cout << v[0];
        for (size_t i = 1; i < v.size(); i++)
        {
            cout << ' ' << v[i];
        }
        cout << endl;

    }

    return 0;
}
