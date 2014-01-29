/****
 * 673 - Parentheses Balance
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

const char * out[2] = {"No\n", "Yes\n"};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char buf[132];

    int n;
    cin >> n;
    cin.ignore(1);
    while (n-- > 0)
    {
        cin.getline(buf, 132);
        stack<char> st;

        bool r = true;
        for (int i = 0; buf[i] != 0; i++)
        {
            if (buf[i] == ']' || buf[i] == ')')
            {
                if (st.empty() || st.top() != buf[i])
                {
                    r = false;
                    break;
                }
                else
                    st.pop();

            }
            else if (buf[i] == '[')
            {
                st.push(']');

            }
            else if (buf[i] == '(')
            {
                st.push(')');
            }
        }

        r &= st.empty();

        cout << out[r];
    }
    return 0;
}
