#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    while (getline(cin, s)) {
        if (s == ".") break;
        stack<char> parenthesis;
        int sz = s.size();
        bool is_balanced = true;
        for (int i=0; i<sz; i++) {
            if (s[i]=='(' || s[i]=='[') { parenthesis.push(s[i]); }
            else if (s[i]==')' || s[i]==']') {
                if (!parenthesis.empty() && (char)(s[i]-(s[i]==')'?1:2))==parenthesis.top()) parenthesis.pop();
                else {is_balanced=false; break;}
            }
        }
        if (!parenthesis.empty()) is_balanced = false;
        cout << (is_balanced ? "yes" : "no") << '\n';
    }

    return 0;
}