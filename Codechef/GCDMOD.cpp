#include <bits/stdc++.h>
#define M 1000000007

using namespace std;
typedef vector <int> vi;
typedef long long ll;

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll phi(ll x);
ll modExp(ll base, ll exp, ll mod);
inline ll mult(ll a, ll b, ll mod);


int main()
{
    int t;
    scanf("%d", &t);

    ll a, b, n;
    while (t--)
    {
        scanf("%lld%lld%lld", &a, &b, &n);
        if (a - b == 0)
            printf("%lld\n", 2*modExp(a, n, M) % M);
        else
        {
            printf("%lld\n", gcd(abs(a - b), modExp(a, n, abs(a - b)) + modExp(b, n, abs(a - b))) % M);
        }
    }
    return 0;
}

ll gcd(ll a, ll b)
{
    ll r;
    while (b)
    {
        r = b;
        b = a % b;
        a = r;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return abs(a * b)/gcd(a, b);
}

ll phi(ll x)
{
    ll r = x;
    for (int i = 2; i*i <= x; ++i)
    {
        if (x % i == 0)
            r -= r/i;
        while (x % i == 0)
            x /= i;
    }

    if (x > 1) r -= r / x;
    return r;
}

ll modExp(ll base, ll exp, ll mod)
{
    ll r = 1;
    base = base % mod;

    while (exp)
    {
        if (exp & 1) 
            r = mult(r, base, mod);
        exp >>= 1;
        base = mult(base, base, mod);
    }

    return r;
}

inline ll mult(ll a, ll b, ll mod)
{
	return (a * b - (ll) ((long double) a * b / mod) * mod + mod) % mod;
}