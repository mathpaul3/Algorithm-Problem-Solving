#include <iostream>
using namespace std;

long long N, cnt=0;
long long r, rr, y, x, upper_limit, lower_limit;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    r=N/2; y=r-1; x=0;
    rr = r*r;

    while (y>=0) {
        long long inner=y*y+x*x, outer=(y+1)*(y+1)+(x+1)*(x+1);
        if (inner<rr && rr<outer) {
            x++;
            cnt++;
        } else if (inner>=rr) {
            y--;
            x--;
        } else if (rr>=outer) {
            x++;
        }
    }
    cout << cnt*4 << '\n';

    return 0;
}