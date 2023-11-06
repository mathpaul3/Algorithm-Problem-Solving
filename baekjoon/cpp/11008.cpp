#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int time=0;
        string s, p;
        cin >> s >> p;
        for (int i=0; i<s.size(); i++) {
            int cur = 0;
            while (cur<p.size() && i+cur<s.size() && s[i+cur]==p[cur]) cur++;
            if (cur==p.size()) { i += cur-1; }
            time++;
        }
        cout << time << '\n';
    }
    return 0;
}