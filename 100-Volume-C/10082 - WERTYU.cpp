/****
 * 10082 - WERTYU
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const char ascii[128] = {
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
 ' ',   0,   0,   0,   0,   0,   0, ';',   0,   0,   0,   0, 'M', '0', ',', '.',
 '9', '`', '1', '2', '3', '4', '5', '6', '7', '8',   0, 'L',   0, '-',   0,   0,
   0, '!', 'V', 'X', 'S', 'W', 'D', 'F', 'G', 'U', 'H', 'J', 'K', 'N', 'B', 'I',
 'O', '!', 'E', 'A', 'R', 'Y', 'C', 'Q', 'Z', 'T', '!', 'P', ']', '[',
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char buf[100];

    while (cin.getline(buf, 100) != NULL)
    {
        for (int i = 0; buf[i] !=0; i++)
            buf[i] = ascii[buf[i]];
        cout << buf << endl;
    }

    return 0;
}
