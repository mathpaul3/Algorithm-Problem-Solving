#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    string encrypted, decrypted;
    cin >> n;
    cin.ignore();
    getline(cin, encrypted);
     for (int i=0; i+1<encrypted.size(); i+=2) {
        if (encrypted[i]==' ') { decrypted += ' '; i--; }
        else if (encrypted[i+1]==' ') decrypted += ' ';
        else decrypted += (encrypted[i] + encrypted[i+1] - n - 2*'a' + 26)%26 + 'a';
    }
    cout << decrypted << '\n';
    return 0;
}