#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int scene;
    cin >> scene;
    for (int i=1; i<=scene; i++) {
        int N, arr[1000]={0,}, cnt=0;
        cin >> N;
        for (int j=0; j<N; j++) cin >> arr[j];
        for (int j=1; j<N; j++) {
            for (int k=j; k>0; k--) {
                if (arr[k]<arr[k-1])
                { cnt++; arr[k] ^= arr[k-1]; arr[k-1] ^= arr[k]; arr[k] ^= arr[k-1]; }
            }
        }
        cout << "Scenario #" << i << ":\n" << cnt << "\n\n";
    }
    return 0;
}