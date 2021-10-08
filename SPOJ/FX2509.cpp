#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exp(ll x, ll y)
{
    ll r = 1;

    while (y)
    {
        if (y & 1)
            r *= y;
        x *= x;
        y >>= 1;
    }

    return r;
}

ll cal(ll x, ll y, char c)
{
    if (c == '^')
        return exp(x, y);
    if (c == 'x')
        return x * y;
    if (c == '/')
        return x / y;
    if (c == '+')
        return x + y;
    if (c == '-')
        return x - y;
}

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == 'x' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

string postfix(const string& s)
{
    string pfix;
    stack <char> oprtor;

    for (size_t i = 0; i < s.size(); ++i)
        if (prec(s[i]))
        {
            while (!oprtor.empty() && prec(oprtor.top()) >= prec(s[i]))
            {
                pfix += oprtor.top();
                oprtor.pop();
            }
            oprtor.push(s[i]);
        }
        else
            if (s[i] == '(')
                oprtor.push(s[i]);
            else
                if (s[i] == ')')
                {
                    while (oprtor.top() != '(')
                    {
                        pfix += oprtor.top();
                        oprtor.pop();
                    }
                    oprtor.pop();
                }
                else
                    pfix += s[i];

    while (!oprtor.empty())
    {
        pfix += oprtor.top();
        oprtor.pop();
    }

    return pfix;
}

ll cal(string& s)
{
    s = postfix(s);
    stack <ll> val;
    int x, y;
    for (size_t i = 0; i != s.size(); ++i)
        if (prec(s[i]))
        {
            x = val.top();
            val.pop();
            y = val.top();
            val.pop();
            val.push(cal(y, x, s[i]));
        }
        else
            val.push(s[i] - 48);

    return val.top();
}

int main()
{
    string s;
    cin >> s;
    cout << cal(s) << endl;

    return 0;
}
