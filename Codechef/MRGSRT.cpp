#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;

void merge(int l, int r, int n, int& depth)
{
    if (n < l || n > r)
    {
        depth = -1;
        return;
    }

    ++depth;
    printf("%d %d\n", l, r);
    if (l < r)
    {
        int m = (l + r) / 2;
        n <= m ? merge(l, m, n, depth) : merge(m + 1, r, n, depth);
    }
}

int main()
{
    int t;
    cin >> t;
    
    int l, r, i, d;
    while (t--)
    {
        d = 0;
        cin >> l >> r >> i;
        merge(l, r, i, d);
        cout << d << "\n";
    }

    return 0;
}
