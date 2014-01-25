/****
 * 299 - Train Swapping
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    vector<int> v;

    cin >> n;
    while (n-- > 0)
    {
        int l;
        cin >> l;

        for (int i = 0; i < l; i++)
        {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }

        int sum = 0;
        while (!v.empty())
        {
            int d = distance(v.begin(), min_element(v.begin(), v.end()));
            sum += d;
            v.erase(v.begin() + d);
        }

        cout << "Optimal train swapping takes " << sum << " swaps.\n";
    }

    return 0;
}
