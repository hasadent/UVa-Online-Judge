/****
 * 344 - Roman Digititis
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct{
    int i, v, x, l, c;
} roman_num_chars;

roman_num_chars rn[101];
int cx = 0;

roman_num_chars int_to_rnc(int i)
{
    roman_num_chars r;
    memset(&r, 0, sizeof(r));

    if (i >= 100) // C
    {
        r.c += i / 100;
        i %= 100;
    }

    if (i >= 90) // XC
    {
        r.c += 1;
        r.x += 1;
        i -= 90;
    }

    if (i >= 50) // L
    {
        r.l += 1;
        i -= 50;
    }

    if (i >= 40) // XL
    {
        r.l += 1;
        r.x += 1;
        i -= 40;
    }

    if (i >= 10) // X
    {
        r.x += i / 10;
        i %= 10;
    }

    if (i >= 9) // IX
    {
        r.x += 1;
        r.i += 1;
        i -= 9;
    }

    if (i >= 5) // V
    {
        r.v += 1;
        i -= 5;
    }

    if (i >= 4) // IV
    {
        r.v += 1;
        r.i += 1;
        i -= 4;
    }

    r.i += i;

    return r;
}

roman_num_chars operator+(const roman_num_chars & a, const roman_num_chars & b)
{
    roman_num_chars r;
    r.c = a.c + b.c;
    r.l = a.l + b.l;
    r.x = a.x + b.x;
    r.v = a.v + b.v;
    r.i = a.i + b.i;
    return r;
}

ostream & operator<<(ostream & os, const roman_num_chars & v)
{
    os << v.i << " i, "
       << v.v << " v, "
       << v.x << " x, "
       << v.l << " l, "
       << v.c << " c";
    return os;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    memset(&rn[0], 0, sizeof(rn[0]));
    cx = 1;

    for (;;)
    {
        int n;
        cin >> n;
        if (n == 0) break;

        for (; cx <= n; cx++)
            rn[cx] = rn[cx-1] + int_to_rnc(cx);

        cout << n << ": " << rn[n] << endl;
    }

    return 0;
}
