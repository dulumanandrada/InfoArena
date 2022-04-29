#include <iostream>
#include <fstream>
#include <unordered_set>
#define N 100001

using namespace std;

ifstream fin ("muzica.in");
ofstream fout ("muzica.out");
unordered_set<long long> v(N);

long long n, m, a, b, c, d, e;
long long piesa, ct, i;

int main()
{
    fin >> n >> m;
    fin >> a >> b >> c >> d >> e;

    for(i = 1; i <= n; ++i)
    {
        fin >> piesa;
        v.insert(piesa);
    }

    if(v.find(a) != v.end())
    {
        ct++;
        v.erase(a);
    }

    if(v.find(b) != v.end())
    {
        ct++;
        v.erase(b);
    }

    for(i = 3; i <= m; ++i)
    {
        piesa = (c * b + d * a) % e;
        if(v.find(piesa) != v.end())
        {
            ct++;
            v.erase(piesa);
        }
        a = b;
        b = piesa;
    }
    fout << ct;
    return 0;
}