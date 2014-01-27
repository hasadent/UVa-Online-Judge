/****
 * 382 - Perfection
 */
#include <iostream>
#include <iomanip>
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

    cout << "PERFECTION OUTPUT\n";

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;

        int sum = 0;
        for (int i = 2; i <= n; i++)
            if (n % i == 0)
                sum += n/i;

        cout << setw(5) << n;
        if (n == sum)
            cout << "  PERFECT\n";
        else if (n < sum)
            cout << "  ABUNDANT\n";
        else
            cout << "  DEFICIENT\n";

    }

    cout << "END OF OUTPUT\n";

    return 0;
}
