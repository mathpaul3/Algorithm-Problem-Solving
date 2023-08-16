#include <iostream>
using namespace std;

int main() {
    bool plane[101][101]={0,};
    int ldx, ldy, rux, ruy, cnt=0;
    for (int i=0; i<4; i++) {
        cin >> ldx >> ldy >> rux >> ruy;
        for (int i=ldy; i<ruy; i++)
            for (int j=ldx; j<rux; j++)
                plane[i][j] = true;
    }
    for (int i=1; i<101; i++)
        for (int j=1; j<101; j++)
            if (plane[i][j]) cnt++;
    cout << cnt << '\n';
    return 0;
}