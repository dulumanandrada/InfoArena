#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("alibaba.in");
ofstream fout("alibaba.out");

int n, k;      
deque<int> d;

int main()
{
    fin >> n >> k;
    char c;         ///vom citi fiecare cifra ca un caracter
    int x;

    for(int i = 1; i <= n; i++)
    {
        fin >> c;
        x = c - '0';
        
        while(d.empty() == 0 && k != 0 && x > d.back())
        {
            d.pop_back();
            k --;
        }
        d.push_back(x);
    }

    while(k != 0)
    {
        d.pop_back();
        k --;
    }

    while(d.empty() == 0)
    {
        fout << d.front();
        d.pop_front();
    }

    return 0;
}