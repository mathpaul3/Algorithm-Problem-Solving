#include <iostream>
using namespace std;

int N, M, table[1024][1024];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> table[i][j];
            if (i) table[i][j] += table[i-1][j];
            if (j) table[i][j] += table[i][j-1];
            if (i && j) table[i][j] -= table[i-1][j-1];
        }
    }

    int x1, y1, x2, y2, sum;
    while (M--) {
        cin >> y1 >> x1 >> y2 >> x2;
        x1--; y1--; x2--; y2--;
        sum = table[y2][x2] - (y1>0 ? table[y1-1][x2] : 0) - (x1>0 ? table[y2][x1-1] : 0) + ((y1>0 && x1>0) ? table[y1-1][x1-1] : 0);
        cout << sum << '\n';
    }

    return 0;
}