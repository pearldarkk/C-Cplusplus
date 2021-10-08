#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;
vector<bool> used;
int n;

void gen(int x) {
    for (int i = 1; i <= n; ++i)
        if (!used[i]) {
            v[x] = i;
            used[i] = 1;
            if (x == n) {
                for (int i = 1; i <= n; ++i)
                    cout << v[i];
                cout << ' ';
            } else
                gen(x + 1);
            used[i] = 0;
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
        cin >> n;
        used.resize(0);
        used.resize(n + 1);
        v.resize(n + 1);
        gen(1);
        cout << endl;
    }

    return 0;
}