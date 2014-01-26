/****
 * 483 - Word Scramble
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char input[1024];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (cin.getline(input, 1024) != NULL)
    {
        char *current = input, *p, *q;

        while (*current != 0)
        {
            while (*current == ' ') current++;

            for (q = p = current; *q != ' ' && *q != 0; q++);

            current = q;
            q--;

            for (char t; p < q; p++, q--)
            {
                t  = *p;
                *p = *q;
                *q = t;
            }
        }

        cout << input << endl;
    }

    return 0;
}
