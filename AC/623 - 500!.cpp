/****
 * 623 - 500!
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define BIG_NUM_SIZE 680

class big_num
{
    int num[BIG_NUM_SIZE];

public:
    big_num();
    void operator= (const int i);
    big_num operator* (const int i);
    friend ostream& operator<<(ostream& os, const big_num& dt);

};

big_num::big_num()
{

}

void big_num::operator=(int i)
{
    memset(num, 0, sizeof(num));

    num[BIG_NUM_SIZE-2] = i / 10000;
    num[BIG_NUM_SIZE-1] = i % 10000;
    i /= 10000;
    num[BIG_NUM_SIZE-3] = i / 10000;
    num[BIG_NUM_SIZE-2] = i % 10000;
}

big_num big_num::operator*(const int n)
{
    big_num r;

    for (int i = 0; i < BIG_NUM_SIZE; i++)
    {
        r.num[i] = num[i] * n;
    }

    for (int i = BIG_NUM_SIZE - 1; i > 0; i--)
    {
        r.num[i-1] += r.num[i] / 10000;
        r.num[i]   = r.num[i] % 10000;
    }

    return r;
}

ostream& operator<<(ostream& os, const big_num& bn)
{
    int i = 0;
    while (i < BIG_NUM_SIZE && bn.num[i] == 0) i++;

    if (i == BIG_NUM_SIZE)
    {
        os << "0";
    }
    else
    {
        os << bn.num[i];
        i++;
    }

    if (i < BIG_NUM_SIZE)
    {
        for (; i < BIG_NUM_SIZE; i++)
            os << setfill('0') << setw(4) << bn.num[i];
    }

    return os;
}

big_num fact[1001];
int f;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    fact[0] = 1;
    fact[1] = 1;

    int y = 1;
    for (f = 2; f <= 12; f++)
    {
        y *= f;
        fact[f] = y;
    }
    f--;

    int n;
    while (cin >> n)
    {
        while (f < n)
        {
            f++;
            fact[f] = fact[f-1] * f;
        }

        cout << n << "!\n" << fact[n] << endl;
    }

    return 0;
}
