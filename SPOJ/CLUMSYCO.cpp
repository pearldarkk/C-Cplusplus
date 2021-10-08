#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

int main()
{
    int d = 0;
    int r = 0;
    string s;
    getline(cin, s);

    for (auto it = s.begin(); *it; ++it)
    if (*it == '(')
        ++d;
    else
    {
        if (d) 
            --d;
        else
        {
            ++d;
            ++r;
        }
    }
    r += d / 2;
    cout << r << endl;

    return 0;
}
