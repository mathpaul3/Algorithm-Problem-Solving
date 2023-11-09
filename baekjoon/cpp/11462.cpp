#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    while (cin >> s) {
        if (s == "END") break;
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i]!='0') {s[i] -= 1; break;}
        }
        cout << stoi(s) << '\n';
    }
    return 0;
}