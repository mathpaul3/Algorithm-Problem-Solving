#include <iostream>
#include <algorithm>
using namespace std;

int A[20000]={0,}, B[20000]={0,};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, N, M;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i=0; i<N; i++) cin >> A[i];
        for (int i=0; i<M; i++) cin >> B[i];
        sort(A, A+N); sort(B, B+M);
        int cnt=0, cur=0;
        for (int i=0; i<N; i++) {
            while ((cur<M) && (A[i]>B[cur])) cur++;
             cnt += cur;
        }
        cout << (cur ? cnt : cur) << '\n';
    }
    return 0;
}