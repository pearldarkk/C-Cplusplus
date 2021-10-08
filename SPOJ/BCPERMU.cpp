#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int p[15],
    n;
bool used[15] = {0};

void out()
{
    for (int i = 1; i <= n; ++i)
        cout << p[i];
    cout << endl;
}

void gen(int k)
{
    for (int i = 1; i <= n; ++i)
        if (!used[i])
        {
            p[k] = i;
            used[i] = 1;
            if (k == n)
                out();
            else
                gen(k + 1);
            used[i] = 0;
        }
}

int main()
{
    cin >> n;
    gen(1);
    return 0;
}
