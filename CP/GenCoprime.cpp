//Couting pairs of coprimes from (1,1) to (n,n)
/*  For example, if n = 4, you need to precalculate 11 values: 
    Answer(1, 1), Answer(1, 2), Answer(2, 1), Answer(1, 3), Answer(2, 3), 
    Answer(3, 2), Answer(3, 1), Answer(1, 4), Answer(3, 4), Answer(4, 3) and Answer(4, 1).

    The solution here is to let res(i) be the minimum number of Answer(x, y) to precalculate, 
        where x, y Î{1, …, i}. 
    It is obvious that res(1) = 1, because if n = 1, it is enough to know Answer(1, 1). 
    Let we know res(i). 
    So for n = i + 1 
        we need to find Answer(1, i + 1), Answer(2, i + 1), … ,
        Answer(i + 1, i + 1), Answer(i + 1, 1), Answer(i + 1, 2), … , Answer(i + 1, i).

    The values Answer(j, i + 1) and Answer(i + 1, j), j Î{1, …, i + 1}, can be found from known values 
        if GCD(j, i + 1) > 1, i.e. if the numbers j and i + 1 are not common primes. 
    So we must know all the values Answer(j, i + 1) and Answer(i + 1, j) for which j and i + 1 are coprime. 
    The number of such values equals to 2 * φ (i + 1), where φ is an Euler’s totient function. 
    So we have a recursion to solve a problem:

    res(1) = 1,
    res(i + 1) = res(i) + 2 * j (i + 1), i > 1
*/
#include <bits/stdc++.h>
using namespace std;

int phi(int x)
{
    int r = x;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            r -= r / i;
        while (x % i == 0)
            x /= i;
    }

    if (x > 1)
        r -= r / x;
    return r;
}

int pairCount(int x)
{
    if (x == 1)
        return 1;
    return pairCount(x - 1) + 2 * phi(x);
}

int main()
{
    int n;
    cin >> n;
    cout << pairCount(n) << endl;

    return 0;
}