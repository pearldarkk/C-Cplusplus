#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii bag;
bool tried[105], chosen[105];
int n, m,
    val = 0;
float g = 0;

bool custom(const ii &a, const ii &b)
{
    return ((float)a.second / a.first) < ((float)b.second / b.first);
}

void setup()
{
    cin >> n >> m;
    int v, w;
    bag.push_back({0, 0});
    for (int i = 1; i <= n; ++i)
    {
        cin >> w >> v;
        bag.push_back({w, v});
    }

    sort(bag.begin() + 1, bag.end(), custom);
}

void out()
{
    int val = 0;
    for (int i = 1; i <= n; ++i)
        if (chosen[i])
            val += bag[i].second;

    cout << val << endl;
}

void bnB(int k)
{
    for (int i = 1; i >= 0; --i)
    {
        tried[k] = i;
        val += bag[k].second * tried[k];
        m -= bag[k].first * tried[k];
        float gk;
        if (k != n)
            gk = (float)m * bag[k + 1].second / bag[k + 1].first + val;
        else
        {
            gk = (float)val;
            if (m >= 0 && gk > g)
            {
                g = gk;
                for (int i = 1; i <= n; ++i)
                    chosen[i] = tried[i];
            }
        }
        if (gk > g)
            bnB(k + 1);
        val -= bag[k].second * tried[k];
        m += bag[k].first * tried[k];
    }
}

int main()
{
    setup();
    bnB(1);
    out();
    return 0;
}
