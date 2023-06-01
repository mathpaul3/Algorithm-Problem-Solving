#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        long long side[3]={0,}, D, sum, tmp;
        cin >> side[0] >> side[1] >> side[2] >> D;
        sort(side, side+3);
        sum = side[0] + side[1] + side[2] - D;

        tmp = side[0];
        side[0] = (sum/3>tmp ? tmp : sum/3);
        sum -= side[0];

        tmp = side[1];
        side[1] = (sum/2>tmp ? tmp : sum/2);
        sum -= side[1];
        
        side[2] = sum;
        cout << side[0]*side[1]*side[2] << '\n';
    }
    return 0;
}