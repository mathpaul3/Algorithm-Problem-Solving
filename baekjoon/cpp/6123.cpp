#include <iostream>
#include <algorithm>
using namespace std;

int N, L, K, R[100000], cnt=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L >> K;
    for (int i=0; i<N; i++)
        cin >> R[i];
    sort(R, R+N);
    for (int i=0; i<N; i++) {
        if (R[i]<=L) {
            cnt++;
            L += K;
        }
    }
    cout << cnt << '\n';
    return 0;
}