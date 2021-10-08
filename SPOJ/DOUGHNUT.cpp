#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int c[t], k[t], w[t];
    for (int i = 0; i<t; ++i)
    cin >> c[i] >> k[i] >> w[i];

    for (int i = 0; i<t; ++i)
    if (c[i]*w[i]>k[i]) cout << "no" << endl;
    else cout << "yes" << endl;

    return 0;
}
