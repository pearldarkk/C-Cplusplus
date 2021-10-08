#include <bits/stdc++.h>
using namespace std;

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

string postfix(string& s)
{
    string pfix;
    stack <char> oprtor;
    string :: iterator it;
    for (it = s.begin(); it != s.end(); ++it)
        if (prec(*it))
        {
            while (!oprtor.empty() && prec(oprtor.top()) >= prec(*it))
            {
                pfix += oprtor.top();
                oprtor.pop();
            }
            oprtor.push(*it);
        }
        else
            if (*it == '(')
                oprtor.push(*it);
            else
                if (*it == ')')
                {
                    while (oprtor.top() != '(')
                    {
                        pfix += oprtor.top();
                        oprtor.pop();
                    }
                    oprtor.pop();
                }
                else
                    pfix += *it;

    while (!oprtor.empty())
    {
        pfix += oprtor.top();
        oprtor.pop();
    }

    return pfix;
}

int main()
{
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    while (n--)
    {
        getline(cin, s);
        cout << postfix(s) << endl;
    }

    return 0;
}
