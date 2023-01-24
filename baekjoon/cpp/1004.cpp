#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int sx, sy, ex, ey, n, cx, cy, r, sd, ed, cnt=0;
        cin >> sx >> sy >> ex >> ey >> n;
        while (n--) {
            cin >> cx >> cy >> r;
            sd = (sx-cx)*(sx-cx)+(sy-cy)*(sy-cy);
            ed = (ex-cx)*(ex-cx)+(ey-cy)*(ey-cy);
            if ((sd<r*r) ^ (ed<r*r)) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}