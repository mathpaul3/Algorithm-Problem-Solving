#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long T, x, y;
    cin >> T;
    while (T--) {
        long long cnt=0, diff, dist=0, last=1;
        cin >> x >> y;
        diff = y - x;
        for (long long i=1; dist+i*2<=diff; i++) {
            cnt+=2;
            dist += i*2;
            last = i;
        }
        last++;
        if (dist == diff) cout << cnt << '\n';
        else if (dist+last >= diff) cout << cnt+1 << '\n';
        else cout << cnt+2 << '\n';
    }
    return 0;
}