#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    char cur, prev=0;
    int local=0;
    stack<int> s, mul;
    while (cin >> cur) {
        if (cur=='(') {
            s.push(--local);
            mul.push(prev-'0');
            local = 0;
        } else if (cur==')') {
            local = local * mul.top() + s.top();
            mul.pop(); s.pop();
        } else local++;
        prev = cur;
    }
    cout << local << '\n';
    return 0;
}