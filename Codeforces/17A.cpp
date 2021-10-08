//Link problem https://codeforces.com/problemset/problem/17/A?locale=en
#include <bits/stdc++.h>
using namespace std;

void sieve(int x, vector <bool> &prm, vector <int> &pnum)
{
    prm.resize(x+1,true);
    prm[0] = prm[1] = false;

    for (int i = 2; i <= x; ++i)
        if (prm[i])
        {
            pnum.push_back(i);
            for (int j = i*i; j <= x; j += i)
                prm[j] = false;
        }
}

void check(int x, int y, vector <bool> &prm, vector <int> &pnum)
{
    int r = 0;
    
    sieve(x, prm, pnum);
    for (int i = 0; i < pnum.size()-1; ++i)
    {
        if (pnum[i]+pnum[i+1]+1 > x) break;
        if (prm[pnum[i]+pnum[i+1] + 1])
            ++r;
        if (r == y) break;
    }
    if (r < y) cout << "NO";
        else cout << "YES";
    cout << endl;
}

int main()
{
    int n, k;
    vector <bool> prime;
    vector <int> pnum;
    cin >> n >> k;
    cout << "1";
    
    check(n, k, prime, pnum);
    
    return 0;
}




