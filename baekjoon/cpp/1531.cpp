#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int paper[101][101]={0,};
    int N, M, ldx, ldy, rux, ruy, cnt=0;
    cin >> N >> M;
    while (N--) {
        cin >> ldx >> ldy >> rux >> ruy;
        for (int i=ldy; i<=ruy; i++)
            for (int j=ldx; j<=rux; j++)
                paper[i][j]++;
    }
    for (int i=1; i<=100; i++)
        for (int j=1; j<=100; j++)
            if (paper[i][j]>M) cnt++;
    cout << cnt << '\n';
    return 0;
}