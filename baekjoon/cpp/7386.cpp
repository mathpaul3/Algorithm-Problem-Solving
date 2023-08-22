#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int encrypted_alpha[26]={0,}, original_alpha[26]={0,};
    string encrypted, original;
    cin >> encrypted >> original;
    for (int i=0; i<encrypted.size(); i++) {
        encrypted_alpha[encrypted[i]-'A']++;
        original_alpha[original[i]-'A']++;
    }
    sort(encrypted_alpha, encrypted_alpha+26);
    sort(original_alpha, original_alpha+26);
    for (int i=0; i<26; i++) {
        if (encrypted_alpha[i]!=original_alpha[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}