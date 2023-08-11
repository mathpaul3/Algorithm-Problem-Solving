#include <iostream>
using namespace std;

int main() {
    int N, S, R, s, r, team=0;
    int kayak[12]={0,};
    cin >> N >> S >> R;
    for (int i=1; i<=N; i++) kayak[i] = 1;
    while (S--) {
        cin >> s;
        kayak[s]--;
    }
    while (R--) {
        cin >> r;
        kayak[r]++;
    }
    for (int i=1; i<=N; i++) {
        if (!kayak[i]) {
            if (kayak[i-1]==2) {
                kayak[i-1]--; kayak[i]++;
            } else if (kayak[i+1]==2) {
                kayak[i+1]--; kayak[i]++;
            } else team++;
        }
    }
    cout << team << '\n';
    return 0;
}