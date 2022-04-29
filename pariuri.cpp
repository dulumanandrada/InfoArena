#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

ifstream fin ("pariuri.in");
ofstream fout ("pariuri.out");

int n, m;
int timp, bani;
unordered_map<int, int> pariu;

int main()
{
    int i, j;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> m;
        for(j = 0; j < m; j++)
        {
            fin >> timp >> bani;
            pariu[timp] = pariu[timp] + bani; 
        }
    }

    fout << pariu.size() << "\n";
    for(auto i = pariu.begin(); i != pariu.end(); i++)
        fout << i->first << " " << i->second << " ";
    return 0;
}
