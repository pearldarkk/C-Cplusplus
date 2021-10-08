#include <bits/stdc++.h>
using namespace std;

void sieve(int x, vector<bool> &prm)
{
    prm.resize(x + 1, true);
    prm[0] = prm[1] = false;

    for (int i = 2; i * i <= x; ++i)
        if (prm[i])
            if (i * 1ll * i <= x)
                for (int j = i * i; j <= x; j += i)
                    prm[j] = false;
}

void print(int x, vector<bool> &prm)
{
    for (int i = 2; i <= x; ++i)
        if (prm[i])
            cout << i << " ";
}
int main()
{
    int n;
    cin >> n;

    vector<bool> prime;

    sieve(n, prime);
    print(n, prime);

    cout << endl;
    return 0;
}