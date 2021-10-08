#include <bits/stdc++.h>
#define M 1000000007

using namespace std;
typedef unsigned long long ll;

vector <string> split(const string& str)
{
    vector <string> tokens;
    istringstream tokenStream(str);
    string token;

    while (getline(tokenStream, token, ' '))
    {
        tokens.push_back(token);
    }

    return tokens;
}

ll mod(string& str, ll m)
{
    ll r = 0;
    for (int i = 0; i < str.size(); ++i)
        r = (r*10 + (str[i] - 48)) % m;
    return r;
}

ll modExp(string& a, string& b)
{
    ll r = 1;

    ll base = mod(a, 1000000007);
    ll exp = mod(b, 1000000006);

    while (exp)
    {
        if (exp & 1)
            r = (r * base) % M;
        
        base = (base * base) % M;
        exp = exp >> 1;
    }

    return r;
}

int main()
{
    int t;
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        printf("%lld\n", modExp(a, b));
    }

    return 0;
}