#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int r;

    while (b)
    {
        r = b;
        b = a % b;
        a = r;
    }
    return r;

}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n;
        vector <int> a;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            a.push_back(x);
        }

        int check = 0;
        x = a[0];
        for (int i = 1; i < n; ++i)
            x = gcd(x, a[i]);

        if (x == 1) cout << "YES";
            else cout << "NO";
        cout << endl;
    }
}