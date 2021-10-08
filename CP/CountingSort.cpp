#include <bits/stdc++.h>
#define M 1000000007
#define MAX_NUM 100000
#define Pn printf("\n")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

void cnts(int *a, int n)
{
    int ca[n] = {0};

    for (int i = 0; i != n; ++i)
        ++ca[a[i]];

    int j = 0;
    for (int i = 0; i != MAX_NUM; ++i)
        while (ca[i]--)
            a[j++] = i;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i != n; ++i)
        cin >> a[i];

    cnts(a, n);

    for (int i = 0; i != n; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
