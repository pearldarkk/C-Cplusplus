#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;
int n;

void tri(vector<int> &v) {
    if (n < 1)
        return;
    cout << '[';
    for (int i = 0; i < n - 1; ++i)
        cout << v[i] << ' ';
    cout << v[n - 1] << ']' << endl;
    for (int i = 0; i < n - 1; ++i)
        v[i] = v[i] + v[i + 1];
    --n;
    tri(v);
}

int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n);
        for (auto &x : v)
            cin >> x;
        tri(v);
    }

    return 0;
}