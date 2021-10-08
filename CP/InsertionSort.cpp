#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void ins(vi &v, vi ::iterator i)
{
    if (i == v.end())
        return;
    auto j = i;
    int k = *i;

    for (; j > v.begin() && *(j - 1) < k; --j)
        *j = *(j - 1);

    *j = k;
    ins(v, i + 1);
}

int main()
{
    vi v = {1, 3, 5, 94, 325, 23, 45, 5, 435, 6, 3, 6, 436, 4, 6, 43};
    ins(v, v.begin());

    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    return 0;
}
