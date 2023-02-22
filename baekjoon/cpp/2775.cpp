#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, k, n;
    cin >> T;
    while (T--) {
        int story[15]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        cin >> k >> n;
        for (int i=0; i<k; i++) {
            for (int j=1; j<=n; j++) {
                if (!j) continue;
                story[j] += story[j-1];
            }
        }
        cout << story[n] << '\n';
    }
    return 0;
}