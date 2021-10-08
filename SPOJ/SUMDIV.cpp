#include <iostream>
#include <math.h>

using namespace std;

long long divSum(long long x)
{
    long long r = 1;
    long long exp = 1;
    while (x % 2 == 0)
    {
        x >>= 1;
        exp *= 2;
    }
    r *= exp * 2 - 1;

    for (long i = 3; i <= sqrt(x); i += 2)
    {
        exp = 1;
        while (x % i == 0)
        {
            exp *= i;
            x /= i;
        }
        if (exp > 1)
            r *= (exp * i - 1) / (i - 1);
    }

    if (x > 2)
        r *= (x * x - 1) / (x - 1);

    return r;
}

int main()
{
    int n;
    long long a;

    cin >> n;
    while (n--)
    {
        cin >> a;
        cout << divSum(a) << endl;
    }

    return 0;
}
