#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a, b, d = 0;
    cin >> a;
    while (--n)
    {
        b = a;
        cin >> a;
        if (a!=b) ++d;
    }

    cout << d+1;
}
