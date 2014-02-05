/****
 * 442 - Matrix Chain Multiplication
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

struct symbol_t{
    int r, c, s;
    friend symbol_t operator*(const symbol_t &, const symbol_t &);
};

symbol_t operator*(const symbol_t &a, const symbol_t &b)
{
    symbol_t r;
    r.r = a.r;
    r.c = b.c;
    r.s = a.s + b.s + a.r * a.c * b.c;
    return r;
}

symbol_t symbols[128];

const int BUF_SIZE = 1024;
char in[BUF_SIZE]= {0};
bool is_EOF = false;

enum token
{
 A = 1, B, C, D, E,
 F, G, H, I, J,
 K, L, M, N, O,
 P, Q, R, S, T,
 U, V, W, X, Y,
 Z, PL = 1002, PR = 1003};

const int ascii[128] = {
-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0,PL,PR, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O,
 P, Q, R, S, T, U, V, W, X, Y, Z, 0, 0, 0, 0, 0,
};

static int __i = 0;
inline void reset_buf()
{
    __i = 0;
    in[__i] = 0;
}

inline int get_token()
{
    for (;;)
    {
        if (in[__i] == 0)
        {
            if(fgets(in, BUF_SIZE-1, stdin) == NULL)
            {
                is_EOF = true;
                return -1;
            }
            __i = 0;
        }

        int x;
        while ((x = ascii[in[__i]]) == 0) __i++;

        if (x > 0)
        {
            __i++;
            return x;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        char N;
        int R, C;
        scanf("%c %d %d\n", &N, &R, &C);

        symbol_t & x = symbols[N-'A'+1];
        x.r = R;
        x.c = C;
        x.s = 0;
    }

    bool is_ERROR = false;
    stack <int> s;
    int t;
    int tm = 27;

    while (!is_EOF)
    {
        switch (t = get_token())
        {
        default:
            s.push(t);
            break;

        case -1:
            break;

        case PR:
            int m2 = s.top(); s.pop();
            int m1 = s.top(); s.pop();
            s.pop(); // remove ')'

            if (!is_ERROR)
            {
                int y = tm++;

                if (symbols[m1].c == symbols[m2].r)
                {
                    symbols[y] = symbols[m1] * symbols[m2];
                    s.push(y);
                }
                else
                {
                    is_ERROR = true;
                }
            }
            break;
        }

        if (is_ERROR)
        {
            puts("error");
            is_ERROR = false;

            stack<int> s2;
            s.swap(s2);
            reset_buf();

            tm = 27;
        }

        /* accept */
        if (s.size() == 1 && s.top() != PL)
        {
            int x = s.top(); s.pop();
            printf("%d\n", symbols[x].s);
            tm = 27;
        }
    }

    return 0;
}
