#include <iostream>
#include <string>
#include <vector>
using namespace std;

int  n, k;
vector<int> v;

void gen(int x) {
    for (int i = v[x - 1] + 1; i <= n - k + x; ++i) {
        v[x] = i;
        if (x == k) {
            for (int i = 1; i <= k; ++i)
                cout << v[i];
            cout << ' ';
        }
        else gen(x + 1);
    }
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
        v.resize(k + 1);
        gen(1);
        cout << endl;
    }

    return 0;
}