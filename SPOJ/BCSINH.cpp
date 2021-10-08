#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

size_t n;

void Try(string s) {
    if (s.size() == n)
        cout << s << endl;
    else
    {
            Try(s + "0");
            Try(s + "1");
    }
}

int main()
{
    cin >> n;
    Try("");

    return 0;
}
