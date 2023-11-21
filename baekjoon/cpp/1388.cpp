#include <iostream>
using namespace std;

int N, M, col, row;
char prv, flr[50][50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        prv = 0;
        for (int j=0; j<M; j++) {
            cin >> flr[i][j];
            if (prv=='-' && flr[i][j]!=prv) row++;
            prv = flr[i][j];
        }
        if (prv=='-') row++;
    }
    for (int i=0; i<M; i++) {
        prv = 0;
        for (int j=0; j<N; j++) {
            if (prv=='|' && flr[j][i]!=prv) col++;
            prv = flr[j][i];
        }
        if (prv=='|') col++;
    }
    cout << col + row << '\n';
    return 0;
}