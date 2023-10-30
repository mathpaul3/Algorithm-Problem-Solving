#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k;
    while (cin >> n >> k) {
        if (n==-1 && k==-1) break;
        int poly[10001]={0,};
        for (int i=0; i<=n; i++) {
            cin >> poly[i];
        }
        for (int i=n; i-k>=0; i--) {
            poly[i-k] -= poly[i];
            poly[i] = 0;
        }
        int until=-1;
        for (; --k>=0;) {
            if (poly[k]) {until=k; break;}
        }
        if (until==-1) cout << 0;
        else
            for (int i=0; i<=until; i++)
                cout << poly[i] << ' ';
        cout << '\n';
    }
    return 0;
}