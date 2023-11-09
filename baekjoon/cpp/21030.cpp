#include <iostream>
using namespace std;

int N, alpha[26], maximum=0;
string S, T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> S >> T;
    for (int i=0; i<N; i++) {
        if (S[i]!=T[i]) alpha[T[i]-'a']++;
        alpha[S[i]-'a']++;
    }
    for (int i=0; i<26; i++) 
        if (maximum<alpha[i]) maximum = alpha[i];
    cout << maximum << '\n';
    return 0;
}