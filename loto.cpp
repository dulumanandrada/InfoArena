#include <iostream>
#include <fstream>
#include <unordered_map>
#define N 10001

using namespace std;
 
ifstream fin("loto.in");
ofstream fout("loto.out");
 
struct trio 
{
    int one, two, three;
};

int n, suma_finala, a[N], suma; 
unordered_map <int, trio> S;
 
int main() 
{
    int i, j, k;
    bool ok = 0;
    fin >> n >> suma_finala;

    for (i = 0; i < n; i++)
        fin >> a[i];
 
    for(i = 0; i < n; i++)
        for(j = i; j < n; j++)
            for(k = j; k < n; k++)
            {
                trio aux;
                aux.one = i;
                aux.two = j;
                aux.three = k;
                suma = a[i] + a[j] + a[k];
                S[suma] = aux;
            }
 
    for(i = 0; i < n && ok == 0; i++)
        for(j = i; j < n && ok == 0; j++)
            for(k = j; k < n && ok == 0; k++)
            {
                suma = a[i] + a[j] + a[k];
                suma = suma_finala - suma;
                if (S.find(suma) != S.end())
                {
                    trio aux = S[suma];
                    fout << a[i] << " " << a[j] << " " << a[k] << " " << a[aux.one] << " " << a[aux.two] << " " << a[aux.three] << "\n";
                    ok = 1;
                }
            }
 
    if (ok == 0)
        fout << -1;
 
    return 0;
}