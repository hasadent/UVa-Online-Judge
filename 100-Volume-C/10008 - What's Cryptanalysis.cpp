/****
 * 10008 - What's Cryptanalysis?
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int c[128];

bool is_empty(int i)
{
    return c[i] == 0;
}

bool is_less(int i, int j)
{
    if (c[i] == c[j])
        return i < j;
    else
        return c[i] > c[j];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char buf[100];

    int n;

    memset(c, 0 , sizeof(c));
    cin >> n;
    cin.ignore(1);
    while (n-- > 0)
    {
        cin.getline(buf, 100);
        for (char * p = buf; *p != 0; p++)
            c[toupper(*p)]++;
    }


    vector<int> v;
    for (int i = 'A'; i <= 'Z'; i++)
        v.push_back(i);

    v.erase(remove_if(v.begin(), v.end(), is_empty), v.end());


    sort(v.begin(), v.end(), is_less);

    for (size_t i = 0; i < v.size(); i++)
        cout << (char)v[i] << " " << c[v[i]] << endl;

    return 0;
}
