#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, N;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N;
        int arr[N];
        for (int i=0; i<N; i++) cin >> arr[i];
        while (N>2) {
            for (int i=0; i<(N/2+N%2); i++) arr[i] += arr[N-i-1];
            N = N/2 + N%2;
        }
        cout << "Case #" << t << ": " << (arr[0]>arr[1] ? "Alice\n" : "Bob\n");
    }
    return 0;
}