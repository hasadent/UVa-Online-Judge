/****
 * 10137 - The Trip
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

    int n;
    for(;;)
    {
        cin >> n;

        if (n == 0) break;

        vector<double> v;
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            double x;
            cin >> x;
            sum += x;
            v.push_back(x);
        }

        double mean = (int)(sum * 100 / n + 0.5);
        mean /= 100;

        double d1 = 0.0, d2 = 0.0;
        for (size_t i = 0; i < v.size(); i++)
            if (v[i] > mean)
                d1 += v[i] - mean;
            else
                d2 += mean - v[i];

        if (d2 < d1)
            d1 = d2;

        cout << '$' << setprecision(2) << fixed << d1  << endl;
    }
    return 0;
}
