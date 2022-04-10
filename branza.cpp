#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("branza.in");
ofstream fout("branza.out");

int N, S, T;
long long total;
deque <pair<long long, long long>> d;
///in coada vom pastra perechea(indice sapt, pret)


int main()
{
    int i, cant, pret;
    fin >> N >> S >> T;

    for(i = 0; i < N; i++)
    {
        ///citim cant si pretul din saptamana curenta
        fin >> pret >> cant;
        
        while(d.empty() == 0 && pret < d.back().second + S * (i - d.back().first))
            d.pop_back();

        d.push_back(make_pair(i, pret));

        ///daca trece perioada maxima de depozitare, eliminam acea varianta
        if(d.front().first < i - T)
            d.pop_front();

        total += cant * (d.front().second + S * (i - d.front().first));
    }

    fout << total;
    return 0;
}