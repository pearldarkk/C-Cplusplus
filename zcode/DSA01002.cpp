#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("text.inp", "r", stdin);
    int t, n, k;
    cin >> t;
    vector<int> v;
    while (t--) {
        cin >> n >> k;
        v.resize(k);
        for (auto &x : v)
            cin >> x;
        int i = k - 1;
        while (i >= 0 && v[i] == n - k +i + 1)
            --i;
        if (i < 0) {
            for (int i = 0; i < k; ++i)
                v[i] = i + 1;
        } else {
            ++v[i];
            for (int j = i + 1; j < k; ++j)
                v[j] = v[i] + j - i;
        }
        for (int i = 0; i < k; ++i)
            cout << v[i] << ' ';
        cout << endl;
    }
}