/****
 * 10106 - Product
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int len_1, len_2;
char input_1[300];
char input_2[300];
int  mult_result[500];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (cin.getline(input_1, 300) != NULL)
    {
        cin.getline(input_2, 300);

        int i;
        for (i = 0; input_1[i] != 0; i++)
            input_1[i] -=  '0';
        len_1 = i;

        for (i = 0; input_2[i] != 0; i++)
            input_2[i] -=  '0';
        len_2 = i;

        memset(mult_result, 0, sizeof(mult_result));


        // multiply
        for (int i_1 = len_1 - 1; i_1 >= 0; i_1 --)
            for (int i_2 = len_2 - 1; i_2 >= 0; i_2 --)
        {
            int t = 500 - 1 - (len_1 - 1 - i_1) - (len_2 - 1 - i_2);
            //cout << i_1 << "," << i_2 << "," << t << endl;

            mult_result[t] += input_1[i_1] * input_2[i_2];
        }

        // carry
        for (i = 500 - 1; i > 0; i--)
        {
            mult_result[i-1] += mult_result[i] / 10;
            mult_result[i] = mult_result[i] % 10;
        }

        // output
        bool is_leading_zero = true;
        for (i = 0; i < 500; i++)
            if (mult_result[i] != 0 || !is_leading_zero)
            {
                cout << mult_result[i];
                is_leading_zero = false;
            }
        if (i == 500 && is_leading_zero)
            cout << "0";
        cout << endl;
    }

    return 0;
}
