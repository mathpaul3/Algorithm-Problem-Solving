#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, X, H[100000]={0,};
    cin >> N >> M >> X;
    for (int i=0; i<M; i++) cin >> H[i];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (N-i>X)
                cout << (N-i <= H[j] ? '#' : '.');
            else if (N-i==X)
                cout << (N-i <= H[j] ? '*' : '-');
            else {
                if (N-i <= H[j]) cout << '#';
                else cout << ((j+1)%3 ? '.' : '|');
            }
        }
        cout << '\n';
    }
    return 0;
}