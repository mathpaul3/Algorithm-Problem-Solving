#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    while (true) {
        cin >> s;
        if (s == "0")
            break;

        int l=0, r=s.size()-1;
        bool is_palindrome = true;
        for (; l<r; l++, r--) {
            if (s[l] != s[r]) {
                is_palindrome = false;
                break;
            }
        }
        cout << (is_palindrome ? "yes" : "no") << '\n';
    }

    return 0;
}