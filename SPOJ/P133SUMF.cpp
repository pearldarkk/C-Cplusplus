#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (b>c) swap(b,c);
    if (a>b) swap(a,b);
    if (b>c) swap(b,c);

    int d1 = b - a;
    int d2 = c - b;

    if (d1==d2) cout << d1 + c;
    else if (d2==2*d1) cout << (c + b)/2;
    else if (d1==2*d2) cout << (a + b)/2;

    return 0;
}
