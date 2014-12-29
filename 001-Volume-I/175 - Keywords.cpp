/****
 * 175 - Keywords
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct {
    int threshold;
    int  wordnum;
    char data[512];
    char * words[100];
} profile;


typedef struct {
    int  wordnum;
    char data[512];
    char * words[100];
} title;

profile p[51];
int     pc = 0;
title   t[251];
int     tc = 0;

inline int find_words(title & tx, profile & px, int start, int skip, int & index)
{
    for (int i = start; i < tx.wordnum; i++)
        for (int j = 0; j < px.wordnum; j++)
        {
            if (skip == j) continue;
            if (strcmp(px.words[j], tx.words[i]) == 0)
            {
                index = j;
                return i;
            }
        }

    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char input[256];
    for (;;)
    {
        gets(input);
        if (input[0] == '#') break;

        if (input[0]== 'P')
        {
            bool scanning_word = false;

            profile & px = p[pc++];
            px.threshold = atoi(input+3);
            px.wordnum   = 0;

            for (int i = 3, j = 0; input[i] != 0; i++)
            {
                char & c = input[i];
                if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
                {
                    if (!scanning_word)
                        px.words[px.wordnum ++] = px.data+j;
                    scanning_word = true;
                    px.data[j++] = c | 0x20;
                }
                else
                {
                    if (scanning_word)
                    {
                        px.data[j++] = '\0';
                        scanning_word = false;
                    }
                }
            }

            /*printf("P ----\n");
            for (int i = 0; i < px.wordnum; i++)
                printf("%d %s\n", i, px.words[i]);*/

        }
        else if (input[0]== 'T')
        {
            bool done = false;
            bool scanning_word = false;

            title & tx = t[tc++];
            tx.wordnum = 0;

            for (int j = 0;;)
            {
                for (int i = 3; input[i] != 0; i++)
                {
                    char & c = input[i];
                    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
                    {
                        if (!scanning_word)
                            tx.words[tx.wordnum ++] = tx.data+j;
                        scanning_word = true;
                        tx.data[j++] = c | 0x20;
                    }
                    else if (c == '|')
                    {
                        tx.data[j] = '\0';
                        done = true;
                        break;
                    }
                    else if (('0' <= c && c <= '9') ||
                             c == '\'' || c =='(' || c == ')' || c == '-')
                    {}
                    else
                    {
                        if (scanning_word)
                        {
                            tx.data[j++] = '\0';
                            scanning_word = false;
                        }
                    }
                }

                if(done) break;
                tx.data[j++] = '\0';
                gets(input);
            }

            /*printf("T ----\n");
            for (int i = 0; i < tx.wordnum; i++)
                printf("%d %s\n", i, tx.words[i]);*/

        }
    }

    for (int i = 0; i < pc; i++)
    {
        profile & px = p[i];
        int mcount = 0;
        bool found;

        printf("%d: ", i+1);
        for (int j = 0; j < tc; j++)
        {
            title & tx = t[j];
            int curr, curr_index;
            int last = find_words(tx, px, 0, -1, curr_index);
            found = false;
            while (last != -1)
            {
                curr = find_words(tx, px, last+1, curr_index, curr_index);

                if (curr == -1)
                {
                    found = false;
                    break;
                }
                else if ((curr - last - 1) <= px.threshold)
                {
                    //fprintf(stderr, "found %d-%d\n", last, curr);
                    found = true;
                    break;
                }

                last = curr;
            }

            if (found)
            {
                if (mcount != 0) printf(",");
                printf("%d", j+1);
                mcount ++;
            }
        }
        printf("\n");
    }


#ifndef ONLINE_JUDGE
    //system("pause");
#endif
    return 0;
}
