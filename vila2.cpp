#include <iostream>
#include <fstream>
#include <deque>
#define N 100005

using namespace std;

ifstream fin("vila2.in");
ofstream fout("vila2.out");

int v[N], n, k;
deque<int> vmin;    ///vom retine indicele varstelor minime
deque<int> vmax;    ///vom retine indicele varstelor maxime

int main()
{
    int i, dif, difmax = -1;

    fin >> n >> k;
    for(i = 0; i < n; i++)
    {
        fin >> v[i];

        while(vmin.empty() == 0 && v[i] <= v[vmin.back()])
            vmin.pop_back();
        vmin.push_back(i); 

        while(vmax.empty() == 0 && v[i] >= v[vmax.back()])
            vmax.pop_back();
        vmax.push_back(i);

        if(vmin.front() == i - (k + 1))
            vmin.pop_front();
        if(vmax.front() == i - (k + 1))
            vmax.pop_front();
        
        if(i >= k)
        {
            dif = v[vmax.front()] - v[vmin.front()];
            if(dif > difmax) difmax = dif;
        }
    }

    fout << difmax;
    return 0;
}