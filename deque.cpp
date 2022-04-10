#include <iostream>
#include <fstream>
#include <deque>
#define N 5000001

using namespace std;

ifstream fin("deque.in");
ofstream fout("deque.out");

deque <int> d;
long long x[N];

int main()
{
    int n, k, i;
    long long s = 0;
    fin >> n >> k;
    
    for(i = 1; i <= n; i++)
        fin >> x[i];

    for(i = 1; i <= n; i++)
    {
        while(d.empty() == 0 && x[d.back()] >= x[i])
            d.pop_back();
        d.push_back(i);
        if(i >= k)
        {
            s += x[d.front()];
            if(d.front() == i - k + 1)
                d.pop_front();
        }  
    }
    fout << s;
    return 0;
}