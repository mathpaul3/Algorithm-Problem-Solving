#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int M, N, U, L, R, D;
    char c;
    cin >> M >> N;
    cin >> U >> L >> R >> D;
    for (int i=0; i<U+M+D; i++) {
        for (int j=0; j<L+N+R; j++) {
            if (U<=i && i<U+M && L<=j && j<L+N) {
                cin >> c; cout << c;
            } else cout << ((i+j)%2 ? '.' : '#');
        }
        cout << '\n';
    }
    return 0;
}