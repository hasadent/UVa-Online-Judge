/****
 * 495 - Fibonacci Freeze
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class big_num
{
    static const int BIG_NUM_SIZE = (1100/4);
    int num[BIG_NUM_SIZE];
public:
    big_num();
    void operator= (const int);
    void operator= (const char *);
    big_num operator* (const int);
    big_num & operator+= (const big_num &);
    big_num & operator= (const big_num &);
    friend ostream& operator<<(ostream& os, const big_num& dt);
};

big_num::big_num()
{}

void big_num::operator=(const int i)
{
    memset(num, 0, sizeof(num));
    int j = i;

    num[BIG_NUM_SIZE-2] = j / 10000;
    num[BIG_NUM_SIZE-1] = j % 10000;
    j /= 10000;
    num[BIG_NUM_SIZE-3] = j / 10000;
    num[BIG_NUM_SIZE-2] = j % 10000;
}

big_num & big_num::operator+=(big_num const &rhs)
{
    for (int i = 0; i < BIG_NUM_SIZE; i++)
        num[i] += rhs.num[i];

    for (int i = BIG_NUM_SIZE - 1; i > 0; i--)
    {
        num[i-1] += num[i] / 10000;
        num[i]   =  num[i] % 10000;
    }

    return *this;
}

big_num & big_num::operator=(big_num const &rhs)
{
    for (int i = 0; i < BIG_NUM_SIZE; i++)
        num[i] += rhs.num[i];

    return *this;
}

ostream& operator<<(ostream& os, const big_num& bn)
{
    int i = 0;
    while (i < big_num::BIG_NUM_SIZE && bn.num[i] == 0) i++;

    if (i == big_num::BIG_NUM_SIZE)
    {
        os << "0";
    }
    else
    {
        os << bn.num[i];
        i++;
    }

    if (i < big_num::BIG_NUM_SIZE)
    {
        for (; i < big_num::BIG_NUM_SIZE; i++)
            os << setfill('0') << setw(4) << bn.num[i];
    }

    return os;
}

big_num f[5001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= 5000; i++)
    {
        f[i] = f[i-1];
        f[i] += f[i-2];
    }

    int n;
    while (scanf("%d", &n) != EOF)
    {
        cout << "The Fibonacci number for " << n << " is " << f[n] << "\n";
    }

    return 0;
}
