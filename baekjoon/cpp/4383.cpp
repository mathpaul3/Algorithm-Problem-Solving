#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, prv, cur, dif;
    while (cin >> n) {
        bool is_jolly = true, diff[3000]={0,};
        cin >> prv;
        for (int i=1; i<n; i++) {
            cin >> cur;
            dif = (cur>prv ? cur-prv : prv-cur);
            if (dif<n) diff[dif] = true;
            prv = cur;
        }
        for (int i=1; i<n; i++) {
            if (!diff[i]) { is_jolly = false; break; }
        }
        cout << (is_jolly ? "Jolly\n" : "Not jolly\n");
    }
    return 0;
}