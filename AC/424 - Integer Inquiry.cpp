/****
 * 424 - Integer Inquiry
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int len;
char input[200];
int  result[200];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    memset(result, 0, sizeof(result));

    while (cin.getline(input, 200) != NULL)
    {
        if (input[0] == '0' && input[1] == 0)
            break;

        int i;
        for (i = 0; input[i] != 0; i++)
            input[i] -=  '0';
        len = i;

        // add
        for (int i = len - 1; i >= 0; i --)
        {
            int t = 200 - 1 - (len - 1 - i);
            //cout << i_1 << "," << i_2 << "," << t << endl;
            result[t] += input[i];
        }
    }

    // carry
    int i;
    for (i = 200 - 1; i > 0; i--)
    {
        result[i-1] += result[i] / 10;
        result[i] = result[i] % 10;
    }

    // output
    bool is_leading_zero = true;
    for (i = 0; i < 200; i++)
        if (result[i] != 0 || !is_leading_zero)
        {
            cout << result[i];
            is_leading_zero = false;
        }
    if (i == 200 && is_leading_zero)
        cout << "0";
    cout << endl;

    return 0;
}
