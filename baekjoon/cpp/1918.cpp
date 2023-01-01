#include <iostream>
#include <stack>
using namespace std;

stack<char> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string expr;
    cin >> expr;

    int size = expr.size();
    for (int i=0; i<size; i++) {
        // cout << expr[i];
        if (expr[i]>64) {
            cout << expr[i];
        } else if (expr[i] == '*' || expr[i] == '/') {
            while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                cout << s.top();
                s.pop();
            }
            s.push(expr[i]);
        } else if (expr[i] == '+' || expr[i] == '-') {
            while (!s.empty() && ((int)s.top() > 41)) {
                cout << s.top();
                s.pop();
            }
            s.push(expr[i]);
        } else if (expr[i] == '(') {
            s.push(expr[i]);
        } else if (expr[i] == ')') {
            while (!s.empty() && (s.top() != '(')) {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}