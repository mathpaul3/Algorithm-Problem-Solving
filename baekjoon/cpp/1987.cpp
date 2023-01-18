#include <iostream>
using namespace std;

char map[20][20]= {0, };
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int R, C, M=0;

void DFS(unsigned int used, int i, int j, int depth) {
    for (int a=0; a<4; a++) {
        int y = i + dy[a];
        int x = j + dx[a];
        if (0<=x && x<C && 0<=y && y<R && (!(used & (1 << (map[y][x]-'A')))))
            DFS(used + (1 << (map[y][x]-'A')), y, x, depth+1);
    }
    if (M < depth) M = depth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            cin >> map[i][j];
    
    DFS((1 << (map[0][0]-'A')), 0, 0, 1);
    cout << M << '\n';
    return 0;
}
