#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;
string tmp;
int T, flag;

int main() {
    cin >> T;
    while(T--)
    {
        cin >> tmp;
        flag = 1;
        for (auto c: tmp)
        {
            if (c == '(')
                s.push('(');
            else if (c == ')')
            {
                if (s.empty())
                {
                    flag=0; 
                    break;
                }
                s.pop();
            }
        }
        cout << (flag && s.empty() ? "YES" : "NO") << endl;
        
        while(!s.empty())
            s.pop();
    }
    return 0;
}