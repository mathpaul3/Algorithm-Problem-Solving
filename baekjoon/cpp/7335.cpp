#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M;
    cin >> M;
    cin.ignore();
    while (M--) {
        string str, ans="";
        int sz; bool is_minus=false;
        stack<bool> stack;
        getline(cin, str);

        sz = str.size();
        for (int i=0; i<sz; i++) {
            if (str[i]=='(') {
                stack.push(is_minus);
                if (stack.top()) ans += '(';
                is_minus = false;
            } else if (str[i]==')') {
                if (stack.top()) ans += ')';
                stack.pop();
                is_minus = false;
            } else if (str[i]=='-') {
                ans += str[i];
                is_minus = true;
            } else if (str[i]!=' ') {
                ans += str[i];
                is_minus = false;
            }
        }
        str = ans;
        ans = "";
        sz = str.size();
        for (int i=0; i<sz; i++) {
            if (str[i]=='(' && str[i+2]==')') {
                continue;
            } else if (str[i]==')' && str[i-2]=='(') {
                continue;
            } else {
                ans += str[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}