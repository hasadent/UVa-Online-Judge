/****
 * 10340 - All in All
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char input[1000000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (cin.getline(input, 1000000) != NULL)
    {
        char *str_1, *str_2;

        str_1 = input;

        for (str_2 = input; *str_2 != ' '; str_2 ++);
        *str_2 = 0; str_2++;

        while (*str_1 != 0 && *str_2 != 0 )
        {
            while (*str_2 != 0 && *str_1 != *str_2) str_2++;

            if (*str_1 == *str_2) {str_1++, str_2++;}
        }


        if (*str_1 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";

    }

    return 0;
}
