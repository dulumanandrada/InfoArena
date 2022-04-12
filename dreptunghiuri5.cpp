#include <iostream>
#include <fstream>
#include <stack>
#define N 1005

using namespace std;

ifstream fin ("dreptunghiuri5.in");
ofstream fout ("dreptunghiuri5.out");
 
int n,m;
int v[N]; 
bool a[N][N];
 
stack<pair <int, int>> mystack;

void Border()
{
    for(int i = 0; i <= n+1; i++)
        {
            a[i][0] = 1;
            a[i][m+1] = 1;
        }
    for(int j = 0; j <= m+1; j++)
        {
            a[0][j] = 1;
            a[n+1][j] = 1;
        }
}

int main() 
{
    int i, j;
    fin >> n >> m;

    Border();

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            fin >> a[i][j];

    int ct = 0, st, dr;

    for(i = 1; i <= n; i++)
    {
        while(mystack.empty() == 0)
            mystack.pop();
        mystack.push(make_pair(0, 0));
        dr = 0;

        for(j = 1; j <= m; j++)
        {
            if(a[i][j] != 0) v[j] = 0;
            else v[j] ++;

            st = j;
            while(mystack.top().first > v[j])
            {
                if(dr >= mystack.top().second) ct++;
                st = mystack.top().second;
                mystack.pop();
            }

            if(mystack.top().first != v[j])
                mystack.push(make_pair(v[j], st));
            if(a[i+1][j] != 0)  dr = j;
        }

        while(mystack.top().first != 0)
        {
            if(dr >= mystack.top().second)  ct++;
            mystack.pop();
        }
    }

    fout << ct;
    return 0;
}