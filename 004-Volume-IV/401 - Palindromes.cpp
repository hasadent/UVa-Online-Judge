/****
 * 401 - Palindromes
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const char rev[128] = {
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0, '1', 'S', 'E',   0, 'Z',   0,   0, '8',   0,   0,   0,   0,   0,   0,   0,
   0, 'A',   0,   0,   0, '3',   0,   0, 'H', 'I', 'L',   0, 'J', 'M',   0, 'O',
   0,   0,   0, '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5',
};

const char * out[4] = {
    " -- is not a palindrome.\n\n",
    " -- is a regular palindrome.\n\n",
    " -- is a mirrored string.\n\n",
    " -- is a mirrored palindrome.\n\n",
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char buf[24];
    bool first = true;

    while (cin.getline(buf, 24) != NULL)
    {
        int len = strlen(buf);

        int r = 0;
        char *p, *q;

        // test palindrome
        for (p = buf, q = buf + len - 1;
            p < q && *p == *q;
            p++, q--);

        r += p < q ? 0 : 1;

        // test mirror
        for (p = buf, q = buf + len - 1;
            p <= q && *p == rev[*q];
            p++, q--);

        r +=  p <= q ? 0 : 2;

        cout << buf << out[r];
    }

    return 0;
}
