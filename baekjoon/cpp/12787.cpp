#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, M;
    unsigned long long N, fragment;
    char period;
    cin >> T;
    while (T--) {
        N = 0;
        cin >> M;
        if (M==1) {
            cin >> fragment;
            N += (fragment << 56);
            for (int i=6; i>=0; i--) {
                cin >> period >> fragment;
                N += (fragment << (i*8));
            }
            cout << N << '\n';
        } else {
            cin >> N;
            for (int i=7; i>=0; i--) {
                cout << ((N/((unsigned long long)1 << (i*8))) % (1<<8));
                if (!i) continue;
                cout << '.';
            }
            cout << '\n';
        }
    }
    return 0;
}