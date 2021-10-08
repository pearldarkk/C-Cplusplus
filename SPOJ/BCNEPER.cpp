#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void nextpermu(int n, string &s)
{
    int len = s.size();
    int i;
    for (i = len - 2; s[i] >= s[i + 1]; --i)
        ;

    if (i == -1)
    {
        cout << n << " " << "BIGGEST" << endl;
        return;
    }

    int j;
    for (j = len - 1; s[j] <= s[i]; --j)
        ;

    swap(s[i], s[j]);

    ++i;
    for (j = len - 1; i < j; ++i, --j)
        swap(s[i], s[j]);

    cout << n << " " << s << endl;
}

int main()
{
    int t;
    cin >> t;

    int n;
    string s;
    while (t--)
    {
        cin >> n >> s;
        nextpermu(n, s);
    }

    return 0;
}
