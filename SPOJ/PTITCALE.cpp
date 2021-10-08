#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exp(ll x, ll y)
{
    ll r = 1;

    while (y)
    {
        if (y & 1)
            r *= x;
        x *= x;
        y >>= 1;
    }

    return r;
}

ll cal(ll x, ll y, char c)
{
    if (c == '^')
        return exp(x, y);
    if (c == '*')
        return x * y;
    if (c == '/')
        return (int) x / y;
    if (c == '+')
        return x + y;
    if (c == '-')
        return x - y;
}

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

ll evaluate(string &s)
{
    stack <char> oprtor;
    stack <ll> oprand;
    string :: iterator it;
    ll a, b, n = 0;
    for (it = s.begin(); it < s.end(); ++it)
    {
        if (*it >= 48 && *it <= 57)
        {
            n = 0;
            for (; *it >= 48 && *it <= 57; ++it)
                n = n * 10 + (*it - 48);
            oprand.push(n);
        }
        if (prec(*it))
        {
            while (!oprtor.empty() && prec(oprtor.top()) >= prec(*it))
            {
            a = oprand.top();
            oprand.pop();
            b = oprand.top();
            oprand.pop();
            oprand.push(cal(b, a, oprtor.top()));
            oprtor.pop();
            }
            oprtor.push(*it);
        }
        else
            if (*it == '(')
                oprtor.push('(');
            else
                if (*it == ')')
                {
                    while (oprtor.top() != '(')
                    {
                        a = oprand.top();
                        oprand.pop();
                        b = oprand.top();
                        oprand.pop();
                        oprand.push(cal(b, a, oprtor.top()));
                        oprtor.pop();
                    }
                    oprtor.pop();
                }
    }

    while (!oprtor.empty())
    {
        a = oprand.top();
        oprand.pop();
        b = oprand.top();
        oprand.pop();
        oprand.push(cal(b, a, oprtor.top()));
        oprtor.pop();
    }

    return oprand.top();
}

int main()
{
    string s;
    int t;
    cin >> t;
    getline(cin, s);
    while (t--)
    {
        getline(cin, s);
        cout << evaluate(s) << endl;
    }

    return 0;
}
