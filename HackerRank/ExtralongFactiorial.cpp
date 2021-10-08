#include <bits/stdc++.h>
using namespace std;

typedef vector <short> vi;

vi fact(int x)
{
    vi r;
    r.push_back(1);

    for (int j = 2; j <= x; ++j)
    {
        for (vi::iterator i = r.begin(); i != r.end(); ++i)
            *i *= j;

        for (short i = 0; i < r.size(); ++i)
        {
            if (r[i] < 10) continue;

            if (i == r.size() - 1) r.push_back(0);

            r[i + 1] += r[i] / 10;
            r[i] %= 10;
        }
    }

    return r;
}

void print(int x)
{
    vi r = fact(x);
    for (auto i = r.rbegin(); i != r.rend(); ++i)
        cout << *i;

}

int main()
{
    int n;
    cin >> n;

    print(n);
    cout << endl;

    return 0;
}