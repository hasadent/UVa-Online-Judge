/****
 * 10420 - List of Conquests
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    map<string, int> c2n;
    int n;
    cin >> n;

    string contry;
    string name;
    while (n-- > 0)
    {
        cin >> contry;
        getline(cin, name);
        c2n[contry] += 1;
    }

    for (map<string,int>::iterator it  = c2n.begin(); it != c2n.end(); it++)
    {
        cout << (it)->first << " " << (it)->second << endl;
    }

    return 0;
}

