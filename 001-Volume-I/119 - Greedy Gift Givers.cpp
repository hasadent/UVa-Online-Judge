/****
 * 119 - Greedy Gift Givers
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    bool first = true;
    int n;
    while (cin >> n)
    {
        if (!first)
            cout << endl;
        first = false;

        map <string, int> name_id;
        vector <string> name_list;

        string name;
        for (int i = 0; i < n; i++)
        {
            cin >> name;
            name_id[name] = i;
            name_list.push_back(name);
        }

        int rec[10] = {0};

        for (int i = 0; i < n; i++)
        {
            int money, people;
            cin >> name >> money >> people;

            if (people == 0)
                continue;

            int mpp  = money / people;
            int left = money % people;

            rec [ name_id[name] ] += left - money;
            for (int j = 0; j < people; j++)
            {
                cin >> name;
                rec [ name_id[name] ] += mpp;
            }
        }

        for (size_t i = 0; i < name_list.size(); i++)
        {
            cout << name_list[i] << " " << rec [ name_id[name_list[i]  ]  ] << endl;
        }
    }

    return 0;
}

