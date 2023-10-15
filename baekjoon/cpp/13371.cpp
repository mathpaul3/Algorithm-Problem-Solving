#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long T, n;
    string phrase_set[3]={" dolphin", " jump", "splash"};
    cin >> T;
    while (T--) {
        long long dolphin=0, phrase;
        cin >> n;
        while ((dolphin*(dolphin+1))/2*3 < n) dolphin++;
        n = n-(dolphin*(dolphin-1)/2*3);
        if (dolphin==1) {
            if (n!=3) cout << dolphin;
            cout << phrase_set[n-1] << '\n';
        } else {
            if ((n-1)/dolphin!=2) cout << dolphin;
            cout << phrase_set[(n-1)/dolphin];
            if ((n-1)/dolphin!=2 && dolphin>1) cout << 's';
            cout << '\n';
        }
    }
    return 0;
}