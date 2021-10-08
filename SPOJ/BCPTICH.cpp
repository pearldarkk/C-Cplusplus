#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        int count = 0;
        cin >> x >> x;
        x *= 2;
        for (int i = 2; i <= sqrt(x); ++i)
            if (x%i == 0)
                if ((x / i + 1 - i) % 2 == 0) ++count;
        cout << i << " " << count << endl;
    }

    return 0;
}