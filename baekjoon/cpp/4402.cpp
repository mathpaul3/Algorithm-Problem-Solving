#include <iostream>
using namespace std;

char soundexify(char c) {
    if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='H' || c=='W' || c=='Y') return 0;
    else if (c=='L') return '4';
    else if (c=='R') return '6';
    else if (c=='D' || c=='T') return '3';
    else if (c=='M' || c=='N') return '5';
    else if (c=='B' || c=='F' || c=='P' || c=='V') return '1';
    else return '2';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string word;
    while (cin >> word) {
        string soundex;
        char prv=soundexify(word[0]), cur;
        if (prv) soundex += prv;
        for (int i=1; i<word.size(); i++) {
            cur = soundexify(word[i]);
            if (cur && prv!=cur) soundex += cur;
            prv = cur;
        }
        cout << soundex << '\n';
    }
    return 0;
}