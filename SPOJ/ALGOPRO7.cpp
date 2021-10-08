#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    int a[100001];

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    cin >> a[i];

    sort(a,a+n);
    cout << a[k];
    cout << endl;

    return 0;
}