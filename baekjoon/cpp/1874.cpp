#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> s;
vector<char> cal;
int n, N, i, tmp;

int main() {
    cin >> n;
    N = n;
    i=1;
    while(n--)
    {
        cin >> tmp;
        if (i<=tmp) {
            while(i<=tmp)
            {
                s.push(i++);
                cal.push_back('+');
            }
            if (s.empty() || s.top() != tmp)
            {
                cout << "NO";
                return 0;
            }
            s.pop();
            cal.push_back('-');
        } else {
            if (s.empty())
            {
                cout << "NO";
                return 0;
            }
            while(s.top() != tmp)
            {
                s.pop();
                cal.push_back('-');
                if (s.empty())
                {
                    cout << "NO";
                    return 0;
                }
            }
            s.pop();
            cal.push_back('-');
        }
    }
    for (auto c: cal)
        cout << c << '\n';
    return 0;
}