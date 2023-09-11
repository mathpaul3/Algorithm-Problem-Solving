#include <iostream>
using namespace std;

int main() {
    int start, end;
    bool reverse = false; 
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='(') { reverse = true; start = i; }
        else if (!reverse) cout << s[i];
        else if (s[i]==')') {
            for (int j=i-1; j>start; j--) cout << s[j];
            reverse = false;
        }
    }
    cout << '\n';
    return 0;
}