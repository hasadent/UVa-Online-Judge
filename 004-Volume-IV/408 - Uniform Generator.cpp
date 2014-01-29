/****
 * 408 - Uniform Generator
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    int t;
    if (a < b)
    {
        t = a;
        a = b;
        b = t;
    }

    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int s, m;
    while (cin >> s >> m)
    {
        if (gcd(s, m) == 1)
            cout << setw(10) << s << setw(10) << m << "    Good Choice\n\n";
        else
            cout << setw(10) << s << setw(10) << m << "    Bad Choice\n\n";
    }
    return 0;
}
