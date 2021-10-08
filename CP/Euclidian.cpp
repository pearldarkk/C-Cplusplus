#include <bits/stdc++.h>
using namespace std;

//recursion ver.
int gcd_recur(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

//division ver.
int gcd(int a, int b)
{
    int r;
    while (b)
    {
        r = b;
        b = a % b;
        a = r;
    }
    return r;
}

int lcm(int a, int b)
{
    return abs(a * b) / gcd(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);

    return 0;
}