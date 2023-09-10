#include <iostream>
using namespace std;

bool check_vowel(char c) {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string password;
    while (cin >> password) {
        if (password=="end") break;
        int continuous=0;
        bool has_vowel=false, dble=false, prv = check_vowel(password[0]);
        for (int i=0; i<password.size(); i++) {
            bool cur = check_vowel(password[i]);
            if (cur) has_vowel = true;
            if (cur==prv) {
                if (++continuous>2) break;
            } else continuous = 1;
            if (i && password[i]!='e' && password[i]!='o' && password[i]==password[i-1]) {
                dble = true;
                break;
            }
            prv = cur;
        }
        cout << "<" << password << "> is" << (has_vowel && continuous<3 && !dble ? " " : " not ") << "acceptable.\n"; 
    }
    return 0;
}