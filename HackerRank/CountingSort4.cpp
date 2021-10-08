#define MAX_N 100
#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

void cnts(short *a, string s[], int n)
{
    int cnt[MAX_N] = {0};
    for (int i = 0; i != n; ++i)
        ++cnt[a[i]];
    for (int i = 1; i != MAX_N; ++i)
        cnt[i] += cnt[i - 1];

    string out[n];
    for (int i = n - 1; i >= 0; --i)
    {
        if (i < n/2)
            out[cnt[a[i]] - 1] = "-";
        else out[cnt[a[i]] - 1] = s[i];
        --cnt[a[i]];
    }

    for (int i = 0; i < n; ++i)
        cout << out[i] << " ";
    Pn;
}

int main()
{
    int n;
    cin >> n;

    short a[n];
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> s[i];

    cnts(a, s, n);

    return 0;
}
