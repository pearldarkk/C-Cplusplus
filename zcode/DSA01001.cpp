#include <iostream>
#include <string>
using namespace std;

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, lastPer;
    string x;
    cin >> t;
    while (t--) {
        cin >> x;
        lastPer = 1;
        for (int i = x.size() - 1; i >= 0; --i)
            if (x[i] == '0') {
                x[i] = '1';
                break;
            }
            else x[i] = '0';
        cout << x << endl;
    }
    
    return 0;
}