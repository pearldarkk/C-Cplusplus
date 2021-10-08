#include <bits/stdc++.h>
using namespace std;

typedef queue<int> qi;

int main() {
    int n, x, i;

    int t;
    cin >> t;
    while (t--) {
        qi q;
        cin >> n;
        while (n--) {
            cin >> x;
            switch (x) {
                case 1:
                    cout << q.size() << endl;
                    break;
                case 2:
                    if (q.empty())
                        cout << "YES";
                    else
                        cout << "NO";
                    cout << endl;
                    break;
                case 3:
                    cin >> i;
                    q.push(i);
                    break;
                case 4:
                    if (!q.empty())
                        q.pop();
                    break;
                case 5:
                    if (!q.empty())
                        cout << q.front();
                    else
                        cout << -1;
                    cout << endl;
                    break;
                case 6:
                    if (!q.empty())
                        cout << q.back();
                    else
                        cout << -1;
                    cout << endl;
                    break;
            }
        }
    }
}
