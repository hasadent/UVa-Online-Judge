/****
 * 120 - Stacks of Flapjacks
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <deque>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char buf[300];
    while (gets(buf) != NULL)
    {
        deque<int> st;
        int num = 0;
        int n = 1;
        for (char * p = buf; *p != 0; p ++)
        {
            if ('0' <= *p && *p <= '9')
                num = num * 10 + (*p - '0');
            else
            {
                st.push_back(num);
                num = 0;
                n++;
            }
        }
        st.push_back(num);

        for (size_t i = 0; i < st.size(); i++)
            printf("%d ", st[i]);
        printf("\n");

        int s;
        while ((s = st.size()) != 0)
        {
            int d = distance(st.begin(), max_element(st.begin(), st.end()));

            if (d == s - 1)
            {
                st.pop_back();
            }
            else if (d == 0)
            {
                printf("%d ", n-s+1);
                st.pop_front();
                reverse(st.begin(), st.end());
            }
            else
            {
                reverse(st.begin(), st.begin() + d + 1);
                st.pop_front();
                reverse(st.begin(), st.end());
                printf("%d %d ", n-d, n - s + 1);
            }
        }
        puts("0");
    }

    return 0;
}

