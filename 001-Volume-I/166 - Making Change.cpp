/****
 * 166 - Making Change
 */
#include <cstdio>
#include <cstdlib>
#include <climits>

const int get[] = {
    0, 1, 1, 2, 1, 2, 2, 3, 2, 3,
    1, 2, 2, 3, 2, 3, 3, 4, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6, 5, 6,
    3};

const int coin_value[] = {1, 2, 4, 10, 20, 40};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int pay[200+1];
    int coin[6];
    int value_to_pay;

    for (;;)
    {
        scanf("%d %d %d %d %d %d",
              coin, coin+1, coin+2,
              coin+3, coin+4, coin+5);

        if (coin[0] == 0 && coin[1] == 0 && coin[2] == 0
            && coin[3] == 0 && coin[4] == 0 && coin[5] == 0)
                break;

        float x;
        scanf("%f", &x);
        value_to_pay = (int)((x*100)+0.5) / 5;

        int tvalue = 0;
        for (int i = 0; i < 6; i++)
            tvalue += coin[i] * coin_value[i];
        tvalue = tvalue >= 200 ? 200 : tvalue;

        pay[0] = 0;
        for (int i = 1; i <= 200; i++)
            pay[i] = INT_MAX;

        for (int i = 100; i >= 1; i--)
        {
            int left = i; /* value left */
            int noc  = 0; /* number of coins*/
            for (int j = 5; j >= 0; j--)
            {
                int require = left / coin_value[j];
                require = require < coin[j] ? require : coin[j];

                noc  += require;
                left -= require * coin_value[j];
            }

            if (left == 0)
                pay[i] = noc;
        }

        int opt = pay[value_to_pay];
        for (int i = value_to_pay + 1; i <= tvalue; i++)
        {
            if (pay[i] == INT_MAX) continue;

            int current = pay[i] + get[i - value_to_pay];

            if (current < opt)
                opt = current;
        }

        printf("%3d\n", opt);
    }
#ifndef ONLINE_JUDGE
    //system("pause");
#endif
    return 0;
}
