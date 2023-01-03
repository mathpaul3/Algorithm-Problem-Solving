#include <iostream>
#include <string>
using namespace std;

bool shortcut[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    string s;
    cin >> N;
    getline(cin, s);
    for (int i=0; i<N; i++) {
        bool has_shortcut = false;
        char cur, prev=' ', initial;

        getline(cin, s);
        int sz = s.size();

        // Initial
        for (int j=0; j<sz; j++) {
            cur = s[j];
            if (prev == ' ' && !has_shortcut) {
                if ((int)cur > 90) cur = (char)((int)cur-32);
                if (!shortcut[(int)cur-65]) {
                    shortcut[(int)cur-65] = true;
                    s = s.substr(0, j) + '[' + s[j] + ']' + s.substr(j+1);
                    cout << s << '\n';
                    has_shortcut = true;
                    break;
                }
            }
            prev = cur;
        }

        // Alphabet
        if (!has_shortcut) {
            for (int j=0; j<sz; j++) {
                cur = s[j];
                if (cur == ' ') continue;
                if ((int)cur > 90) cur = (char)((int)cur-32);
                if (!shortcut[(int)cur-65]) {
                    shortcut[(int)cur-65] = true;
                    s = s.substr(0, j) + '[' + s[j] + ']' + s.substr(j+1);
                    cout << s << '\n';
                    has_shortcut = true;
                    break;
                }
            }
        }

        // No shortcut
        if (!has_shortcut) {
            cout << s << '\n';
        }
    }

    return 0;
}