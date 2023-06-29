#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int W, H, X, Y, P, R, x, y, cnt=0;
    cin >> W >> H >> X >> Y >> P;
    R = H/2;
    while (P--) {
        cin >> x >> y;
        if (Y<=y && y<=Y+H) {
            if (X<=x && x<=X+W) cnt++;
            else if (X-R<=x && x<X) {
                if ((X-x)*(X-x)+(Y+R-y)*(Y+R-y)<=(R*R)) cnt++;
            } else if (X+W<x && x<=X+W+R) {
                if ((X+W-x)*(X+W-x)+(Y+R-y)*(Y+R-y)<=(R*R)) cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}