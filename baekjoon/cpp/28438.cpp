#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, Q, q, d, v;
    long long col[500000]={0,}, row[500000]={0,};
    cin >> N >> M >> Q;
    while (Q--) {
        cin >> q >> d >> v;
        if (q==1) row[d-1] += v;
        else col[d-1] += v;
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cout << row[i] + col[j] << ' ';
        cout << '\n';
    }
    return 0;
}