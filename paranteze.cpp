#include <iostream>
#include <fstream>
#include <stack>
#define N 1000005

using namespace std;

ifstream fin("paranteze.in");
ofstream fout("paranteze.out");

int n;                              ///nr de caractere/paranteze date
stack <pair<int, char>> mystack;    ///o stiva pereche (index, paranteza)
int lungime_maxima;                 ///lungimea maxima a unei secvente corect parantezate

int main()
{
    int i, lungime;
    char c;                         ///paranteza citita
    fin >> n; 

    mystack.push(make_pair(' ',-1));            ///daca stiva ar fi goala din prima, nu ar intra pe toate cazurile

    for(i = 0; i < n; i++)
    {
        fin >> c;

        if(c == '(' || c == '{' || c == '[')    ///inceputul unei secvente
            mystack.push(make_pair(i, c));
        else
        {
            if(mystack.empty() == 0)            ///daca stiva ar fi goala, atunci nu ar fi solutie
            {
                if(c == ')' && mystack.top().second == '(') mystack.pop();
                else if(c == ']' && mystack.top().second == '[') mystack.pop();
                    else if(c == '}' && mystack.top().second == '{') mystack.pop();
                        else mystack.push(make_pair(i,c));
                //lungime = i - mystack.top().first;          ///lungimea secventei curente
                lungime_maxima = max(lungime_maxima, i - mystack.top().first);
            }
        }
    }

    fout << lungime_maxima;
}