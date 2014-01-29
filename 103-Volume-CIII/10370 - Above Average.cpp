/****
 * 10370 - Above Average
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int avg = 0;

bool is_less_avg(int i)
{
    return i > avg;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int c;
    cin >> c;
    while (c-- > 0)
    {
        int n;

        cin >> n;

        vector<int> v;
        int sum = 0, x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;

            v.push_back(x);
            sum += x;
        }

        avg = sum / n;
        int y = count_if(v.begin(), v.end(), is_less_avg);

        cout << fixed << setprecision(3) << ((double)y) / n * 100 << "%\n";
    }
    return 0;
}
