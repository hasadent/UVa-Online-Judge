/****
 * 492 - Pig-Latin
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int BUF_SIZE = 4096;
const int OUT_BUF_SIZE = BUF_SIZE + 100;

const int ascii[128] = {
-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2,
 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
 0, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2,
 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
};

char in[BUF_SIZE], out[OUT_BUF_SIZE];

bool is_EOF = false;

inline char _getch()
{
    static int i = 0;

    if (in[i] == 0)
    {
        is_EOF = fgets(in, BUF_SIZE-1, stdin) == NULL;
        i = 0;
    }

    return in[i++];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    in[0] = 0;

    char ch, h, *q = out;

    ch = _getch();
    while (!is_EOF)
    {
        switch (ascii[ch])
        {
        case 1:
            h = ch;
            for (ch = _getch(); ascii[ch] > 0; ch = _getch(), q++)
                *q = ch;
            *q++ = h;
            *q++ = 'a';
            *q++ = 'y';
            break;

        case 2:
            for (; ascii[ch] > 0; ch = _getch(), q++)
                *q = ch;
            *q++ = 'a';
            *q++ = 'y';
            break;

        default:
            *q++ = ch;
            ch = _getch();
            break;
        }

        if (q >= out+BUF_SIZE)
        {
            *q = 0;
            printf(out);
            q = out;
        }
    }

    if (q > out)
    {
        *q = 0;
        printf(out);
    }

    return 0;
}
