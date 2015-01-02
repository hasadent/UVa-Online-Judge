/**
 * 159 - Word Crosses
 */
#include <cstdio>
#include <cstring>

using namespace std;

inline void find_pos(char * str0, char * str1, int & p0, int & p1)
{
    p0 = p1 = -1;
    for (int i = 0; str0[i] != 0; i++)
        for (int j = 0; str1[j] != 0; j++)
            if (str0[i] == str1[j])
            {
                p0 = i;
                p1 = j;
                return;
            }
}


char input[52];
char _h0[32]  = "          ";
char _v0[32]  = "          ";
char _h1[32]  = "          ";
char _v1[32]  = "          ";

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE

    for (int count = 0;; count++)
    {
        gets(input);
        if (input[0] == '#') break;

        if (count != 0) puts("");

        char * h0 = _h0 + 10, * h1 = _h1 + 10;
        char * v0 = _v0 + 10, * v1 = _v1 + 10;
        sscanf(input, "%s %s %s %s", h0, v0, h1, v1);

        int hp0, hp1, vp0, vp1;
        find_pos(h0, v0, hp0, vp0);
        find_pos(h1, v1, hp1, vp1);

        if (hp0 != -1 && hp1 != -1)
        {
            char buf0[30], buf1[30];

            // prepare space;
            int s = 0;
            for (s = 0; s < hp0; s++)
                buf0[s] = ' ';
            buf0[s] = 0;
            for (s = 0; s < strlen(h0) - hp0 + 2 + hp1; s++)
                buf1[s] = ' ';
            buf1[s] = 0;

            // top part
            int max_v = vp0 > vp1 ? vp0 : vp1;
            v0 -= max_v - vp0;
            v1 -= max_v - vp1;
            for (int i = 0; i < max_v; i++)
            {
                if (v1[i] == ' ')
                    printf("%s%c\n", buf0, v0[i]);
                else
                    printf("%s%c%s%c\n", buf0, v0[i], buf1, v1[i]);
            }

            // horizontal words
            printf("%s   %s\n", h0, h1);

            // bottom part
            v0 += max_v + 1;
            v1 += max_v + 1;

            vp0 = strlen(v0);
            vp1 = strlen(v1);
            max_v = vp0 > vp1 ? vp0 : vp1;

            for (s = vp0; s < max_v; s++)
                v0[s] = ' ';
            v0[s] = 0;
            for (s = vp1; s < max_v; s++)
                v1[s] = ' ';
            v1[s] = 0;

            for (int i = 0; i < max_v; i++)
            {
                if (v1[i] == ' ')
                    printf("%s%c\n", buf0, v0[i]);
                else
                    printf("%s%c%s%c\n", buf0, v0[i], buf1, v1[i]);
            }
        }
        else
        {
            puts("Unable to make two crosses");
        }
    }



    return 0;
}

