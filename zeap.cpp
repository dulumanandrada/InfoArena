#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

ifstream fin("zeap.in");
ofstream fout("zeap.out");

string task;
set<int> zeap;
priority_queue<pair<int, pair<int,int>>> MinDif;

int FormareNumar(string s)
{
    int nr = 0, i = 2;
    while(s[i])
    {
        nr = nr * 10 + (s[i] - '0');
        i ++;
    }
    return nr;
}

void Inserare(int x)
{
    if(zeap.find(x) == zeap.end())
    {
        //inseram x
        zeap.insert(x);

        if(zeap.size() >= 2)
        {
            auto it = zeap.find(x);
            //verific daca exista un element in stanga si calculez noua diferenta
            if(it != zeap.begin())
            {
                it--;
                MinDif.push(make_pair(abs(x - *it) * (-1), make_pair(*it, x)));
            }

            //la fel si pentru partea dreapta
            it = zeap.find(x);
            if(it != zeap.end()) 
            {
                it++;
                MinDif.push(make_pair(abs(*it - x) * (-1), make_pair(*it, x)));
            }
        }
    }
}

void Stergere(int x)
{
    if(zeap.find(x) == zeap.end())
        fout << "-1 \n";
    else
    {	
        auto it = zeap.find(x);
        auto right = it;
        right++;
        if(it == zeap.begin() || right == zeap.end())
        {
            zeap.erase(x);
        }
        else
        {
            auto left = it;
            left--;
            if (right != zeap.end() and it != zeap.begin())
                MinDif.push(make_pair(abs(*right - *left) * (-1), make_pair(*left, *right)));
            zeap.erase(x);
        }
    }
}

void Cautare(int x)
{
    if(zeap.find(x) == zeap.end())
        fout << "0 \n";
    else fout << "1 \n";
}

void MIN()
{
    if(zeap.size() < 2)
        fout << "-1 \n";
    else        
    {
       while(zeap.find(MinDif.top().second.first) == zeap.end() || zeap.find(MinDif.top().second.second) == zeap.end())
            MinDif.pop(); 
        fout << (-1) * MinDif.top().first << "\n";
    }
}

void MAX()
{
    if(zeap.size() < 2)
        fout << "-1 \n";
    else
    {
        auto left = zeap.begin();
        auto right = zeap.end();
        right --;
        fout << *right - *left << "\n";
    }
}

int main()
{
    int nr;
    ///citim operatiile
    while(getline(fin, task))
    {
        //inserare
        if(task[0] == 'I')
        {
            nr = FormareNumar(task);
            Inserare(nr);
        }
        //stergere
        else if(task[0] == 'S')
        {
            nr = FormareNumar(task);
            Stergere(nr);
        }
        //cautare
        else if(task[0] == 'C')
        {
            nr = FormareNumar(task);
            Cautare(nr);
        }
        //min
        else if(task == "MIN")
            MIN();
        //max
        else if(task == "MAX")
            MAX();
    }
    return 0;
}