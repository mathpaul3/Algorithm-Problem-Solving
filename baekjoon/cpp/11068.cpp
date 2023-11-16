#include <iostream>
using namespace std;

int T;

bool is_palindrome(int number, int B) {
    string s = "";
    while (number) {
        s += (char)(number%B);
        number /= B;
    }
    for (int i=0; i<s.size()/2; i++)
        if (s[i]!=s[s.size()-i-1]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        int number;
        bool flag = false;
        cin >> number;
        for (int i=2; i<65; i++) {
            if (is_palindrome(number, i)) {
                cout << 1 << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) cout << 0 << '\n';
    }
    return 0;
}