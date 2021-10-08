#define M 1000000007
#define Pn printf("\n")
#define MAX_N 100
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

void print(int *a, int n)
{
    for (int i = 0; i != n; ++i)
        cout << a[i] << " ";
    Pn;
}

void cnts(int *a, int n)
{
    int cnt[105] = {0};

    for (int i = 0; i != n; ++i)
        ++cnt[a[i]];

    for (int i = 1; i != MAX_N; ++i)
        cnt[i] += cnt[i - 1];

    print(cnt, MAX_N);
}

int main()
{
    int n;
    cin >> n;
    
    int a[n];
    string s;
    for (int i = 0; i != n; ++i)
        cin >> a[i] >> s;

    cnts(a, n);

    return 0;
}
