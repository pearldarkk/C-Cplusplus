#include <bits/stdc++.h>
using namespace std;

typedef stack <int> si;

int main()
{
    string str;
    si s;
    int n;
    while (1)
    {
        cin >> str;
        if (str == "init")
            while (!s.empty()) s.pop();
        if (str == "end")
            break;
        if (str == "push")
        {
            cin >> n;
            s.push(n);
        }
        if (str == "pop")
            if (!s.empty())
                s.pop();
        if (str == "top")
        {
            if (s.empty())
                cout << -1;
            else
                cout << s.top();
            cout << '\n';
        }
        if (str == "size")
            cout << s.size() << '\n';
        if (str == "empty")
        {
            if (s.empty())
                cout << 1;
            else
                cout << 0;
            cout << '\n';
        }
    }

    return 0;
}
