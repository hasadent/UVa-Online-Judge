/****
 * 10017 - The Never Ending Towers of Hanoi
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = -1;
const int A = 0;
const int B = 1;
const int C = 2;

const int T[3][3] =
{
    {N, C, B},
    {C, N, A},
    {B, A, N},
};

int n, m;
vector<int> base[3];

inline void print()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << (char)('A' + i) << "=>";
        if (base[i].size() != 0)
            cout << "  ";
        for (size_t t = 0; t < base[i].size(); t++)
            cout << " " << base[i][t];
        cout << endl;
    }
}

inline void move_top(int from, int to)
{
    base[to].push_back(base[from].back());
    base[from].pop_back();
}

void move(int from, int to, int size)
{
    if (m == 0)
        return;

    if (size == 1)
    {
        move_top(from, to);
        print();
        m--;
        return;
    }

    move(from, T[from][to], size - 1);
    if (m == 0) return;

    move_top(from, to);
    print();
    m--;

    move(T[from][to], to, size - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (int k = 1;; k++)
    {
        cin >> n >> m;

        if (n == 0)
            break;

        if (k != 1)
            cout << "\n";
        cout << "Problem #" << k << "\n";

        base[0].clear();
        base[1].clear();
        base[2].clear();

        for (int i = n; i > 0; i--)
            base[0].push_back(i);

        print();
        move(A, C, n);

    }
    cout << endl;

    return 0;
}
