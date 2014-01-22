/****
 * 153 - Permalex
 *
 *  Reference:
 *   http://online-judge.uva.es/board/viewtopic.php?t=3422&highlight=153
 *    algorithm by Nikolay Archak
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int list[128];
int LB, UB;
int n;
char buf[32];
#define OUTPUT_TYPE_FMT "%10llu\n"
typedef unsigned long long output_t;

output_t number_of_permutations(int factorial_n)
{
    output_t num = 1;
    output_t div = 1;


    for (int i = LB; i <= UB; i++)
    {
        for (; num < 0x7fffffffffffff && factorial_n > 1; num *= factorial_n--);

        for (int j = list[i]; j > 1; j--)
            if (num % j == 0) num /= j;
            else div *= j;

        if (div != 1 && num % div == 0)
        {
            num /= div;
            div = 1;
        }
    }

    for (; factorial_n > 1; num *= factorial_n--);
    num /= div;
    return num;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    for (;;)
    {
        gets(buf);
        if (buf[0] == '#')
            break;

        memset(list, 0, sizeof(list));
        for (n = 0; buf[n] != 0; n++)
            list[buf[n]] += 1;

        for (LB = 0+'a'; list[LB] == 0; LB++);
        for (UB = 0+'z'; list[UB] == 0; UB--);

        output_t result = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = LB; j < buf[i]; j++)
            {
                if (list[j] != 0)
                {
                    list[j] --;
                    result += number_of_permutations(n - i - 1);
                    list[j] ++;
                }
            }
            list[buf[i]] --;
        }

        printf(OUTPUT_TYPE_FMT, result);
    }

    return 0;
}

