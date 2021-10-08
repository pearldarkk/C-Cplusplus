#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n, k;

void gen(string s) {
    if (s.size() == n) {
        if (count(s.begin(), s.end(), '1') == k)
            cout << s << endl;
        return;
    }
    gen(s + '0');
    gen(s + '1');
}

int main() {
    //freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        gen("");
    }

    return 0;
}