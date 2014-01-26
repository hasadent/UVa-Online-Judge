/****
 * 10041 - Vito's family
 */
#include <iostream>
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

    int k;
    cin >> k;
    while (k-- > 0)
    {
        int r;
        cin >> r;

        vector<int> f;

        for (int i = 0; i < r; i++)
        {
            int x;
            cin >> x;
            f.push_back(x);
        }

        sort(f.begin(), f.end());
        int home = f[r/2];


        int sum = 0;
        for (vector<int>::iterator it = f.begin(); it != f.end(); it++)
        {
            if (*it > home)
                sum += *it - home;
            else
                sum += home - *it;
        }
        
        cout << sum << endl;
    }

    return 0;
}
