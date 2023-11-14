#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, M, D, W;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int lines=0, prv=0;
        cin >> M >> D >> W;
        while (M--) {
            int tmpD = D;
            if (prv) {
                tmpD -= prv;
                lines++;
            }
            lines += tmpD/W;
            tmpD -= (tmpD/W) * W;
            if (tmpD>0) lines++;
            prv = (W - tmpD) % W;
        }
        cout << "Case #" << t << ": " << lines << '\n';
    }
    return 0;
}