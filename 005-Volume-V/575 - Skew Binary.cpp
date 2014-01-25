/****
 * 575 - Skew Binary
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        char input[40];
        cin.getline(input, 40);


        if (input[0] == '0' && input[1] == 0)
            break;

        unsigned int output = 0;
        int sum = 0;
        for (char * p = input; *p != 0; p++)
        {
            int v = *p - '0';

            output = (output + v) * 2;
            sum += v;
        }

        cout << output - sum << endl;
    }
    return 0;
}
