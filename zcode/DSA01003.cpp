#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("text.inp", "r", stdin);
    int t, n;
    vector<int> v;
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n);
        for (auto &x : v)
            cin >> x;
        int j = n - 2;
        while (j >= 0 && v[j] > v[j + 1])
            --j;
        if (j == - 1)
            for (int i = 0; i < n; ++i)
                v[i] = i + 1;
        else {
            int k = n - 1;
            while (v[j] > v[k])
                --k;
            swap(v[j], v[k]);
            int l = j + 1, r = n - 1;
            while (l < r) {
                swap(v[l], v[r]);
                ++l, --r;
            }
        }
        for (auto x : v)
            cout << x << ' ';
        cout << endl;
    }
    return 0;
}