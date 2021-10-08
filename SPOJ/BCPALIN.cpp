#include <iostream>
using namespace std;

int main()
{
    int n,flip,x,a;
    cin >> a;

    while (a--)
    {
        cin >> n;
        x = n;
        flip = 0;
        while (n)
        {
            flip = flip*10 + n%10;
            n/=10;
        }

        if (flip==x) cout << "YES" << endl;
        else cout << "NO\n" << endl;
    }

    return 0;
}

