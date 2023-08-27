#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, ref[751]={0,}, tmp;
    cin >> N;
    ref[N] = N; tmp = N;
    for (int i=N-1; i>0; i--) {
        ref[tmp+(N%2 ^ i%2 ? -i : i)] = ref[tmp]+2*(i+1)-2;
        tmp += (N%2 ^ i%2 ? -i : i);
    }
    for (short i=1; i<=N; i++) {
        for (short j=1; j<=N; j++)
            cout << (ref[(i>j ^ (N-i+1)<=j ? j : N-i+1)] + (i>j ? N-i-j+1 : i+j-N-1)) << ' ';
        cout << '\n';
    }
    return 0;
}