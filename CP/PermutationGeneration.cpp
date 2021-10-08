#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> permutation(n);
vector<int> used(n, 0);

void coutPermutation()
{
    for (int i = 0; i < n; ++i)
        cout << permutation[i];
    cout << endl;
}

void generation(int element, int index)
{
    permutation[index] = element;
    used[element] = 1;

    if (index == n - 1)
        coutPermutation();
    else
        for (int i = 0; i < n; ++i)
            if (!used[i])
                generation(i, index + 1);

    used[element] = 0;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
        generation(i, 0);

    return 0;
}
