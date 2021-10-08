#include <iostream>
#include <string>
using namespace std;

int n;

void gen(string x) {
    if (x.size() == n) {
        cout << x << ' ';
        return;
    }
    gen(x + 'A');
    gen(x + 'B');
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
        cin >> n;
        gen("");
        cout << endl;
    }

    return 0;
}