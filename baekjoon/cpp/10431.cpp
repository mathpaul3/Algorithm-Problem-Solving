#include <iostream>
using namespace std;

int P, T, height[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> P;
    while (P--) {
        cin >> T;
        int cnt = 0;
        for (int i=0; i<20; i++) {
            cin >> height[i];
            int cur = i;
            while (height[cur-1]>height[cur]) {
                height[cur-1] ^= height[cur];
                height[cur] ^= height[cur-1];
                height[cur-1] ^= height[cur];
                cnt++; cur--;
            }
        }
        cout << T << ' ' << cnt << '\n';
    }
    return 0;
}