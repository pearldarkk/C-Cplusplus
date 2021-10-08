#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

void sieve(int n, vi &prime)
{
    bitset <3200> pMark;
    pMark.set();
    pMark[0] = pMark[1] = 0;

    for (int i = 2; i <= n; ++i)
        if (pMark[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= n; j += i)
                pMark[j] = 0;
        }
}

vi pFact(int n, vi &prime)
{
    vi r;

    int i = 0, f = prime[i];

    while (n != 1 && f*f <= n)
    {
        while (n % f == 0)
        {
            r.push_back(f);
            n /= f;
        }
        f = prime[++i];
    }

    if (n != 1) r.push_back(n);

    return r;
}

int main()
{
    vi prime;
    int n = 3200; 

    sieve(n,prime); //Precompute

    while (scanf("%d", &n) != EOF)
    {
        if (n == 0) break;
        if (n == 1)
        {
            printf("1\n");
            continue;
        }
        vi pf = pFact(n, prime);
        printf("1");
        for (vi::iterator i = pf.begin(); i != pf.end(); ++i)
            printf(" x %d",*i);
        
        printf("\n");
    }

    return 0;
}