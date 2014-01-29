/****
 * 10013 - Super long sums
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;

class big_num
{
    static const int BIG_NUM_SIZE = (1000000/4+1);
    int num[BIG_NUM_SIZE];
public:
    big_num();
    void operator= (const int);
    void operator= (const char *);
    big_num operator* (const int);
    big_num & operator+= (const big_num &);
    friend ostream & operator<<(ostream & os, const big_num & dt);
};

big_num::big_num()
{
}

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

void big_num::operator=(const char *p)
{
    memset(num, 0, sizeof(num));

    int x = BIG_NUM_SIZE-1;
    int len = strlen(p) - 1;
    for (; len >= 3; len -= 4, x--)
    {
        num[x] = (p[len] - '0') + (p[len-1] - '0') * 10 +
            (p[len-2] - '0') * 100 + (p[len-3] - '0') * 1000;
    }

    for (int i = 0; i <= len ; i++)
        num[x] = num[x] * 10 + (p[i] - '0');
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

big_num a, b;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char buf0[1000004], buf1[1000004];
    int n , m;

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &m);

        for (int i = 0; i < m; i++)
            scanf("\n%c %c", buf0+i, buf1+i);
        buf0[m] = buf1[m] = 0;

        a = buf0;
        b = buf1;
        a+= b;

        cout << a ;
        if (n == 0) cout << "\n";
        else cout << "\n\n";
    }

    return 0;
}
