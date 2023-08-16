#include <iostream>
using namespace std;

int main() {
    string document, word;
    int dsz, wsz, cnt=0;
    getline(cin, document);
    getline(cin, word);
    dsz = document.size();
    wsz = word.size();
    for (int i=0; i<=dsz-wsz; i++) {
        if (document[i]==word[0]) {
            bool flag = true;
            for (int j=1; j<wsz; j++) {
                if (document[i+j]!=word[j]) {
                    flag = false; break;
                }
            }
            if (flag) { i += wsz-1; cnt++; }
        }
    }
    cout << cnt << '\n';
    return 0;
}