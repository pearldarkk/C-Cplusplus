#include <bits/stdc++.h>
using namespace std;

int n, k, finish;
int a[100];
vector<int> temp;
vector<vector<int>> v;

void next() {
    int i = k;
    int r, d, s;
    temp.resize(0);
    while (a[i] == 1)
        i = i - 1;
    if (i == 0)
        finish = 1;
    else {
        a[i] = a[i] - 1;
        d = k - i + 1;
        r = d / a[i];
        s = d % a[i];
        k = i;
        if (r > 0) {
            for (int j = i + 1; j <= r + i; ++j)
                a[j] = a[i];
            k = k + r;
        }
        if (s > 0) {
            k = k + 1;
            a[k] = s;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        finish = 0, k = 1;
        a[1] = n;
        while (finish != 1) {
            for (int i = 1; i <= k; ++i)
                temp.push_back(a[i]);
            v.push_back(temp);
            temp.clear();
            next();
        }
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++i) {
            cout << "(";
            for (int j = 0; j < v[i].size(); ++j)
                if (j == v[i].size() - 1)
                    cout << v[i][j];
                else
                    cout << v[i][j] << ' ';
            cout << ") ";
        }
        cout << endl;
        v.clear();
    }
}