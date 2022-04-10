/*
HASHURI ->InfoArena
var1:
    array
var2:
    vector de frecventa
    -dezavantaj: elemente foarte mari
var3:
    HASH-uri
        = un vector cu clase de resturi (liste care vor avea foarte putine elemente)
        h[k]->clasa de rest k, cu k de la 0 la 666013(nr prim foarte mare)
        vom pune x in clasa de rest specifica: x -> x % k;
        Complexitate: O(n/k);
    
    Implementare de mana:
        vector<int> hash[k+5];
        k = cheia
        int clasa = x % k
        found = 0
        for(int i=0; i<hash[clasa].size(); i++)
        if(hash[clasa][i] == x)
        {
            found = 1;
            break;
            swap(i, ultim_elem)
            hash[clasa].pop_back();
        }
        1.hash[clasa].push_back(x)

    --------------------------------------------------------------------------
    //daca avem de exemplu un string, cum facem hash???
    //transformam cuv intr-un polinom cu baza 26 (atatea litere are alfabetul)
    //de ex. casa = (3, 1, 19, 1) in baza 16
    --------------------------------------------------------------------------

    Varianta preimplementata:
    #include <map>
    map<int, int> myhash;   //O(n)
    //unordered_map         //O(1)
    myhash[10^9] = 1;
    !!!!ARE CONSTANTA FOARTE PROASTA -> limita de timp
*/

#include <iostream>
#include <fstream>
#include <vector>
#define N 666013

using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

vector<int> myhash[N+2];

int main()
{
    int n, op, i, x, j;
    int clasa, k = N;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> op >> x;
        bool found = 0;
        clasa = x % k;
        for(j = 0; j < myhash[clasa].size(); j++)
            if(myhash[clasa][j] == x)
            {
                found = 1;
                break;
            }
        if(op == 1)
        {
            if(found == 0)
                myhash[clasa].push_back(x);
        } 
        else if(op == 2)
        {
            if(found == 1)
            {
                swap(myhash[clasa][j], myhash[clasa].back());
                myhash[clasa].pop_back();
            }
        }
        else if(op == 3)
        {
            fout << found << "\n";
        }
    }
}
