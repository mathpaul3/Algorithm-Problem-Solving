#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    while (cin >> s) {
        if (s == "0") return 0;
        int cnt = 2;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '1') cnt += 2;
            else if (s[i] == '0') cnt += 4;
            else cnt += 3;
        }
        cnt += s.size()-1;
        cout << cnt << '\n';
    }
    return 0;
}