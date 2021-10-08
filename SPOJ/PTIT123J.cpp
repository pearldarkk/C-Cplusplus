#include <bits/stdc++.h>
using namespace std;

bool parenthesis(string& s)
{
    stack <char> prthesis;
    string :: iterator it;

    for (it = s.begin(); it != s.end(); ++it)
        switch (*it)
        {
            case '(':
                prthesis.push(0);
                break;
            case ')':
                if (!prthesis.empty() && prthesis.top() == 0)
                    prthesis.pop();
                else 
                    return 0; 
                break;
            case '[':
                prthesis.push(1);
                break;
            case ']':
                if (!prthesis.empty() && prthesis.top() == 1)
                    prthesis.pop();
                else 
                    return 0; 
                break;
            default:
                break;
        }
    
    if (prthesis.empty()) 
        return 1;
    return 0;
}

int main()
{
    string s;
    while (getline(cin, s) && s != ".")
    {
        if (parenthesis(s))
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }

    return 0;
}

