#include <iostream>
#include <algorithm>
using namespace std;

int T, n, x[8], y[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> n;
        int result = 0;
        for (int i=0; i<n; i++) cin >> x[i];
        for (int i=0; i<n; i++) cin >> y[i];
        sort(x, x+n);
        sort(y, y+n);
        for (int i=0; i<n; i++) 
            result += x[i]*y[n-i-1];
        cout << "Case #" << t << ": " << result << '\n';
    }
    return 0;
}