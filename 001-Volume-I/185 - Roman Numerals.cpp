/****
 * 185 - Roman Numerals
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define CORRECT      0
#define INCORRECT    1

#define VALID        0
#define IMPOSSIBLE   2
#define AMBIGUOUS    4

namespace RN
{

enum uppercase_alphabet_values {
    A = 0, B = 0, C = 100, D = 500, E = 0,
    F = 0, G = 0, H = 0, I = 1, J = 0,
    K = 0, L = 50, M = 1000, N = 0, O  = 0,
    P = 0, Q = 0, R = 0, S = 0, T = 0,
    U = 0, V = 5, W = 0, X = 10, Y = 0,
    Z = 0,
};

const int rnv[] = {
    A, B, C, D, E,
    F, G, H, I, J,
    K, L, M, N, O,
    P, Q, R, S, T,
    U, V, W, X, Y,
    Z,};

const int * rnx = rnv - 'A';

int rntoi(char *rn)
{
    int v = 0;
    while (*rn != 0)
    {
        char & c = rn[0];
        char & n = rn[1];

        if (n != 0 && rnx[c] < rnx[n])
            v -= rnx[c];
        else
            v += rnx[c];

        rn ++;
    }
    return v;
}

}/* namespace RN*/

using RN::rntoi;

namespace AN
{
enum char_to_index_value {I = 0, V = 1, X = 2, L = 3, C = 4, D = 5, M = 6};

inline int char_to_index(char c)
{
    if (c == 'I') return I;
    if (c == 'V') return V;
    if (c == 'X') return X;
    if (c == 'L') return L;
    if (c == 'C') return C;
    if (c == 'D') return D;
    if (c == 'M') return M;
    return -1;
}

const char itc[7] = {
    'I', 'V', 'X', 'L', 'C', 'D', 'M'
};

inline char index_to_char(int index)
{
    return itc[index];
}

void count_char_w(int * g_count, char * carray)
{
    int l_count[7] = {};

    while (*carray)
    {
        for (int i = 0; i < 7; i++)
            l_count[i] *= 10;

        int x = char_to_index(*carray);
        l_count[x] += 1;

        carray++;
    }

    for (int i = 0; i < 7; i++)
        g_count[i] += l_count[i];
}

}/* namespace AN */

using AN::count_char_w;
using AN::index_to_char;

char * lhs0, * lhs1, * rhs;
int cw_count[7];

#define IS_LEADING_CHAR(c) ((c) == lhs0[0] || (c) == lhs1[0] || (c) == rhs[0])
int v[7];
int value_to_gen;
int ans_count;



void gen_value(int index)
{
    if (index == 7)
    {
        int sum = 0;
        for (int i = 0; i < 7; i++)
            sum += v[i] * cw_count[i];

        if (sum == 0)
            ans_count += 1;

        return;
    }

    if (cw_count[index] == 0)
    {
        v[index] = 0;
        gen_value(index + 1);
        return;
    }

    char cx = index_to_char(index);
    for (int i = IS_LEADING_CHAR(cx) ? 1 : 0;
        i <= 9; i++)
    {
        v[index] = i;
        gen_value(index + 1);
    }
}

const char output[6][24] = {
    "Correct valid",
    "Incorrect valid",
    "Correct impossible",
    "Incorrect impossible",
    "Correct ambiguous",
    "Incorrect ambiguous",
};

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    char input[40];
    int r;

    for (;;)
    {
        gets(input);
        if (input[0] == '#') break;

        lhs0 = strtok(input, "+=");
        lhs1 = strtok(NULL, "+=");
        rhs  = strtok(NULL, "+=");

        r = (int)(rntoi(lhs0) + rntoi(lhs1) == rntoi(rhs) ? CORRECT : INCORRECT);


        if (strlen(lhs0) + 2 <=  strlen(rhs))
        {
            r |= IMPOSSIBLE;
        }
        else
        {
            int lhs_count[7] = {}, rhs_count[7] = {};
            bool may_ambiguous = false;

            count_char_w(lhs_count, lhs0);
            count_char_w(lhs_count, lhs1);
            count_char_w(rhs_count, rhs);

            value_to_gen = 0;
            for (int i = 0; i < 7; i++)
            {
                cw_count[i] = lhs_count[i] - rhs_count[i];
                value_to_gen  += cw_count[i] != 0 ? 1 : 0;
                may_ambiguous |= lhs_count[i] != 0 && lhs_count[i] == rhs_count[i];
            }

            ans_count = 0;
            gen_value(0);

            if (ans_count == 0)
                r |= IMPOSSIBLE;
            else if (ans_count == 1)
                r |= may_ambiguous ? AMBIGUOUS : VALID;
            else
                r |= AMBIGUOUS;
        }
        puts(output[r]);
    }



#ifndef ONLINE_JUDGE
    //system("pause");
#endif
    return 0;
}
