#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    int digitCount = 0;
    while (n)
    {
        if (n % 10 == 4 || n % 10 == 7)
            ++digitCount;
        n /= 10;
    }

    if (digitCount == 4 || digitCount == 7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
