/****
 * 148 - Anagram checker
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_WORD 24
#define MAX_DICT 2000
int n;
char dict[MAX_DICT][MAX_WORD];
int  len[MAX_DICT];
int char_list[128];
vector<int> st;
char *input, buf[1024];

void dfs(int start)
{
    int i, j;

    for (i = 'A'; i <= 'Z' && char_list[i] == 0; i++);
    if (i == 'Z' + 1)
    {
        /* test if there is any word from input */
        for (i = 0; i < (int)st.size(); i++)
        {
            j = st[i];
            char *p = strstr(input, dict[j]);
            if (p != NULL && *(p-1) == ' ' && (*(p+len[j]) == ' '|| *(p+len[j]) == 0))
                return;
        }

        printf("%s =", input);
        for (i = 0; i < (int)st.size(); i++)
            printf(" %s", dict[st[i]]);
        printf("\n");
        return;
    }

    for (i = start; i < n; i++)
    {
        for (j = 0; dict[i][j] != 0; j++)
        {
            if (char_list[dict[i][j]] == 0)
                break;
            char_list[dict[i][j]] -= 1;
        }

        if (dict[i][j] == 0)
        {
            st.push_back(i);
            dfs(i+1);
            st.pop_back();
        }

        for (j-= 1; j >=0; j--)
            char_list[dict[i][j]] += 1;
    }

    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for(n = 0; ;n++)
    {
        gets(dict[n]);

        if (dict[n][0] == '#')
            break;
        len[n] = strlen(dict[n]);
    }

    input = buf+1;
    buf[0] = ' ';
    for (;;)
    {
        gets(input);

        if (input[0] == '#')
            break;

        memset(char_list, 0, sizeof(char_list));
        st.clear();

        for (int i = 0; input[i] != 0; i++)
            char_list[input[i]] += 1;
        dfs(0);
    }

    return 0;
}

