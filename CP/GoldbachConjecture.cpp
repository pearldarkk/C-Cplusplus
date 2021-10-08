#include <bits/stdc++.h>
using namespace std;
/*  For any integer n (n ≥ 4) there exist two prime numbers p1 and p2 such that p1 + p2 = n. 
    In a problem we might need to find the number of essentially different pairs (p1, p2), 
    satisfying the condition in the conjecture for a given even number n (4 ≤ n ≤ 2^15).
*/
void genPrimes(int x, vector<bool> &prm)
{
    prm.resize(x + 1, true);
    prm[0] = prm[1] = false;

    for (int i = 2; i * i <= x; ++i)
        if (prm[i])
            if (i * 1ll * i <= x)
                for (int j = i * i; j <= x; j += i)
                    prm[j] = false;
}

int pairCount(int x, vector<bool> &prm)
{
    int r = 0;
    for (int i = 2; i <= x / 2; ++i)
        if (prm[i] && prm[x - i])
            ++r;
    return r;
}
int main()
{
    int n;
    cin >> n;
    vector<bool> prime;

    genPrimes(n, prime);
    cout << pairCount(n, prime) << endl;

    return 0;
}