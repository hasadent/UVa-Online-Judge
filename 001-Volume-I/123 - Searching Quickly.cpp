/****
 * 123 - Searching Quickly
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct
{
    int order;
    char * src;
    int offset;
    int length;
}  index_t;

index_t  words[4000];
size_t w;
char   input[100][200];
char   ignore[50][20];
int t;
vector<char *> ignore_list;
vector<index_t *> index_list;

bool cmp(const char *a, const char *b)
{
     return strcmp(a, b) < 0;
}

bool cmp_index(const index_t * a, const index_t * b)
{
    int l = a->length > b->length ? b->length : a->length;

    int c = strncmp(a->src + a->offset, b->src + b->offset, l);
    if (c == 0)
    {
        if (a->length == b->length)
        {
            if (a->order == b->order)
                return a->offset < b->offset;
            return a->order < b->order;
        }
        return a->length < b->length;
    }
    return c < 0;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (int i = 0;; i++)
    {
        gets(ignore[i]);
        if (ignore[i][0] == ':')
            break;

        ignore_list.push_back((ignore[i]));
    }
    sort(ignore_list.begin(), ignore_list.end(), cmp);

    for (int i = 0, w = 0; ; i++)
    {
        if (gets(input[i]) == NULL)
            break;

        char *s = input[i], *x = input[i];
        while (*x != 0)
        {
            /* find begin of next word */
            while (*s == ' ') s++;
            x = s;

            /* find end of the word, and do to lower case*/
            while (*x != ' ' && *x != 0)
            { *x |= 0x20; x++; }
            char t = *x; /* temporal set */
            *x = 0;

            /* find if the word should be ignored */
            bool ignore_word = false;
            for (size_t k = 0; k < ignore_list.size(); k++)
                if (strcmp(s, ignore_list[k]) == 0)
                { ignore_word = true;  break; }

            /* add the word information to index list */
            if (!ignore_word)
            {
                //printf("> add new word '%s'\n", s);
                words[w].order  = i;
                words[w].src    = input[i];
                words[w].length = x - s;
                words[w].offset = s - input[i];
                index_list.push_back(&words[w]);
                w ++;
            }

            *x = t;
            s = x+1;
        }
    }

    sort(index_list.begin(), index_list.end(), cmp_index);

    for (size_t i = 0; i < index_list.size(); i++)
    {
        index_t * ix = index_list[i];
        char  * tr = ix->src + ix->offset;

        /* to uppper */
        for (int j = 0; j < ix->length; j++)
            tr[j] &= 0x5f;

        printf("%s\n", index_list[i]->src);

        /* to lower */
        for (int j = 0; j < ix->length; j++)
            tr[j] |= 0x20;
    }

    return 0;
}

