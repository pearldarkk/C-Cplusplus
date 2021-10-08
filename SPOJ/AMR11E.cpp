//C++14 SIGSEGV while C++ 4.3.2 & C++ Gcc 8.3 AC
#include <iostream>
#include <vector>
using namespace std;

void factors(int x, vector <int> &pfactors)
{
    pfactors.resize(x+1,0);

    for (int i = 2; i <= x; ++i)
        if (pfactors[i] == 0)
            for (int j = i*2; j <= x; j += i)
                ++pfactors[j];
}

void gen(int x, vector <int> &pfactors, vector <int> &num)
{
    for (int i = 30; i < x && num.size() <= 1001; ++i)
        if (pfactors[i] >= 3)
            num.push_back(i);
            
}

int main()
{
    int n = 2700;  //1000th number = 2664
    vector <int> pfactors;
    vector <int> num;

    factors(n, pfactors);
    gen(n, pfactors, num);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << num[n-1] << endl;
    }

    return 0;
}
