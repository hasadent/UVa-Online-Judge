/****
 * 156 - Ananagrams
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define MAX_CHAR   24

char input[MAX_CHAR];
char lower_input[MAX_CHAR];
typedef multimap <string, string> mmap;
mmap m;
vector <string> vec;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%s", input) != EOF && input[0] != '#')
    {
        int i;
        for (i = 0; input[i] != 0; i++)
            lower_input[i] = input[i] | 0x20;
        lower_input[i] = 0;
        sort(lower_input, lower_input+i);

        m.insert(make_pair(lower_input, input));
    }

    for (mmap::iterator it = m.begin(); it != m.end(); it++)
        if (m.count(it->first) == 1)
            vec.push_back(it->second);

    sort(vec.begin(), vec.end());

    for(size_t i = 0; i < vec.size(); i++)
        puts(vec[i].c_str());

    return 0;
}
