#include <iostream>
using namespace std;

int main()
{
    int n;
    long long int a;
    cin >> n;

    while (n--)
    {
        cin >> a;
        if (a%100==86) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
