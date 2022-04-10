#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>

using namespace std;
ifstream fin("queue.in");
ofstream fout("queue.out");

stack<int> st1;
stack<int> st2;

void OpPush(char op[])
{
    int poz = 10, wr = 0;
    while(isdigit(op[poz]))
    {
        wr = wr * 10 + op[poz] - '0';
        poz++;
    }

    //read(wr)
    fout << "read(" << wr << ") ";

    st1.push(wr);
    fout << "push(1," << wr << ") ";

}

void OpPop(char op[])
{
    //fout << "pop";
    int wr;
    
    if(st2.empty() == 0)
    {
        wr = st2.top();
        st2.pop();
        fout << "pop(2) write(" << wr << ") ";
    }
    else 
    {
        while(st1.size() != 1)
        {
            int x = st1.top();
            st1.pop();
            fout << "pop(1) ";

            st2.push(x);
            fout << "push(2," << x << ") ";
        }

        wr = st1.top();
        st1.pop();
        fout << "pop(1) write(" << wr << ") ";
    }
}

int main()
{
    int n, i;
    char op[100];

    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fout << i << ": ";

        fin >> op;
        if(strstr(op, "push"))
            OpPush(op);
        else if(strstr(op, "pop"))
            OpPop(op);
        
        fout << "\n";
    }
    return 0;
}
