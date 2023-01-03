#include <iostream>
using namespace std;

char map[5][5];
int R, C, K, cnt=0;

void DFS(int x, int y, int depth) {
    if (depth == K) {
        cnt += ((x == C-1) && (y == 0));
        return;
    }
    map[y][x] = 'T';

    if ((y > 0) && (map[y-1][x] == '.'))
        DFS(x, y-1, depth+1);
    if ((y+1 < R) && (map[y+1][x] == '.'))
        DFS(x, y+1, depth+1);
    if ((x > 0) && (map[y][x-1] == '.'))
        DFS(x-1, y, depth+1);
    if ((x+1 < C) && (map[y][x+1] == '.'))
        DFS(x+1, y, depth+1);

    map[y][x] = '.';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> K;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> map[i][j];
        }
    }
    DFS(0, R-1, 1);
    cout << cnt << '\n';

    return 0;
}