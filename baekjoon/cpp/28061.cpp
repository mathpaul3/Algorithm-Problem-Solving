#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, ai, M=0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> ai;
        if (M<ai-(N-i)) M = ai-(N-i);
    }
    cout << M << '\n';
    return 0;
}