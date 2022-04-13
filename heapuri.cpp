/*
HEAP-URI:
====================
priority_queue<int> myheap;
myheap.push(x);     //inserare
myheap.pop();       //cel mai mere element
myheap.top();       //stergere

cerinta: minimul din heap?
    1. inmultim cu -1;
cerinta: sterge elem din interior?
    1. al 2-lea pq in care tin elem sterse;
    2. tine un map cu ce elem trebuie sters;
    ex: 3 5 7 10 12
    mymap[7] = 1;   //trebuie sters!
    mymap[7] = 0;   //s-a sters elementul :)

====================
set<int> myset;
myset.insert(x);
myset.erase(...);   //de iterator sau de valoare
myset.begin()       //cel mai mic(iteratorul)
myset.end()         //poz de dupa cel mai mare

myset.erase(myset.find(5))  //sterge primul 5 gasit
myset.erase(5)              //sterge toate val = 5

SET ESTE MAI PUTERNIC!! -dar merge ft ft ft incet

====================
- arbore binar partial complet
- raspunsul este in radacina
- minheap - valoarea dintr-un nod va fi mai mica decat valoarea fiilor
*/

#include <iostream>
#include <fstream>
#define N 200005
#include <set>

using namespace std;

ifstream fin("heapuri.in");
ofstream fout("heapuri.out");

int n, v[N];
set<int> myset;
set<int>::iterator itr;

int main()
{
    int i, op, x, k = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> op;
        if(op == 1)
        {
            fin >> x;
            v[++k] = x;
            myset.insert(x);
        }
        else if(op == 2)
        {
            fin >> x;
            myset.erase(v[x]);
        }
        else if(op == 3)
        {
            itr = myset.begin();
            fout << *itr << "\n";
        }
    }
    return 0;
}
