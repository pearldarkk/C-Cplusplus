#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;
int n;

void tri(vector<int> &v, int n) {
    if (n < 1)
        return;
    vector<int> vtmp(n - 1);
    for (int i = 0; i < n - 1; ++i)
        vtmp[i] = v[i] + v[i + 1];
    tri(vtmp, n - 1);
    cout << '[';
    for (int i = 0; i < n - 1; ++i)
        cout << v[i] << ' ';
    cout << v[n - 1] << ']' << ' ';
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
        v.resize(n);
        for (auto &x : v)
            cin >> x;
        tri(v, n);
        cout << endl;
    }

    return 0;
}