#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, K, i, j, x, y;
    int matrix[301][301]={0,};
    cin >> N >> M;
    for (i=1; i<=N; i++) {
        for (j=1; j<=M; j++) {
            cin >> matrix[i][j];
            matrix[i][j] += matrix[i-1][j];
            matrix[i][j] += matrix[i][j-1];
            matrix[i][j] -= matrix[i-1][j-1];
        }
    }
    cin >> K;
    while (K--) {
        cin >> i >> j >> y >> x;
        cout << matrix[y][x] - matrix[i-1][x] - matrix[y][j-1] + matrix[i-1][j-1] << '\n';
    }
    return 0;
}