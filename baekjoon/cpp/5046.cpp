#include <iostream>
#define MIN_COST 1000000
using namespace std;

int main() {
    int N, B, H, W, p, a, min_cost=MIN_COST;
    cin >> N >> B >> H >> W;
    while (H--) {
        bool flag = true;
        cin >> p;
        if (p*N>B) flag = false;
        for (int i=0; i<W; i++) {
            cin >> a;
            if (!flag) continue;
            if (a>=N && min_cost>p*N) min_cost = p*N;
        }
    }
    if (min_cost==MIN_COST) cout << "stay home\n";
    else cout << min_cost << '\n';
    return 0;
}