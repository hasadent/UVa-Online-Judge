/****
 * 10252 - Common Permutation
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string in1, in2;

    while (getline(cin, in1))
    {
        getline(cin, in2);

        sort(in1.begin(), in1.end());
        //auto it1 = unique(in1.begin(), in1.end());
        //in1.resize(distance(in1.begin(), it1));

        sort(in2.begin(), in2.end());
        //auto it2 = unique(in2.begin(), in2.end());
        //in2.resize(distance(in2.begin(), it2));

        for (size_t i = 0, j = 0; i < in1.size() && j < in2.size(); )
        {
            if (in1[i] == in2[j])
            {
                cout << in1[i];
                i++;
                j++;
            }
            else
            {
                if (in1[i] > in2[j])
                    j++;
                else
                    i++;
            }
        }
        cout << endl;

    }

    return 0;
}
