#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
#define N 100001
using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

stack <long long> st;
char s[N];

int EvalExp()
{
    long long E = 0, i, v, x;
    int nr;
    for(i = 0; s[i]; i++)
    {
        if(s[i] == '(') st.push(-1);
        if(s[i] == '*') st.push(-2);
        if(s[i] == '/') st.push(-3);
        if(s[i] == '-') st.push(-4);

        if(s[i] >= '0' && s[i] <= '9')
        {
            nr = 0;
            while(s[i] >= '0' && s[i] <= '9')
            {
                nr = nr * 10 + (s[i] - '0');
                i ++;
            }
            i --;          

            if(st.top() == -2)
            {
                st.pop();
                v = st.top() * nr;
                st.pop();
                st.push(v);
            }

            else if(st.top() == -3)
            {
                st.pop();
                v = st.top() / nr;
                st.pop();
                st.push(v);
            }
            else if(st.top() == -4)
            {
                st.pop();
                x = st.top() - nr; 
                st.pop();
                st.push(x);
            }

            else st.push(nr);
        }

        if(s[i] == ')')
        {
            v = 0;
            while(!st.empty())
            {
                x = st.top();
                st.pop();
                if(x == -1) break;
                else v = v + x;
            }
        
            if(st.empty()) st.push(v);
            else if(st.top() == -2)
            {
                st.pop();
                x = v * st.top(); 
                st.pop();
                st.push(x);
            }
            else if(st.top() == -3)
            {
                st.pop();
                x = st.top() / v; 
                st.pop();
                st.push(x);
            }
            else if(st.top() == -4)
            {
                st.pop();
                x = st.top() - v; 
                st.pop();
                st.push(x);
            }
            else st.push(v);
        }

    }

    E = 0;
    while(!st.empty())
    {
        E += st.top();
        st.pop();
    }
    return E;
}

int main()
{
    fin >> s;
    st.push(0);
    fout << EvalExp();
    return 0;
}