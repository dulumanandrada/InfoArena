#include <iostream>
#include <fstream>
#include <cstring>
#define N 60001
using namespace std;

int n;
char c, s[N];

ifstream fin ("editor.in");
ofstream fout ("editor.out");

int Test (char s[N], int k)
{
    char t[N] = "";
    int j = -1, i;
    for(i = 0; i <= k; i ++)
        {
            if(s[i] == '[' || s[i] == '(')
                t[++j] = s[i];
            else 
            {
                if(s[i] == ')')
                    {
                        if(t[j] == '(') j--;
                        else return 0;
                    }
                else if(s[i] == ']')
                        {
                            if(t[j] == '[') j--;
                            else return 0; 
                        }
            }
        }   

    if(j == -1) return 1;
    else return 0;
}


int main()
{ 
    fin >> n;
    int i, k = -1;
  
    while(fin >> c)
    {
        if(c == 'E') 
            {
                if(Test(s, k) == 1) 
                    fout << ":)";
                else fout << ":(";
                fout << "\n";
                k = -1;
                char s[] = "";
            }
        else 
        {
            if(c == '*' && k >= 0) k--;
            else s[++k] = c;
        }
    }
    return 0;
}

