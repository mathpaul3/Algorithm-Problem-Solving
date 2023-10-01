#include <iostream>
#include <queue>
using namespace std;

int R, C, cnt=0, mv[4]={0,0,-1,1};
char grid[100][100]={0,};
bool visited[100][100]={0,};

void BFS(int r, int c) {
    queue<pair<int,int> > q;
    q.push(make_pair(r, c));
    while (!q.empty()) {
        int y, x, ny, nx;
        y = q.front().first, x = q.front().second; q.pop();
        for (int i=0; i<4; i++) {
            ny = y+mv[i], nx = x+mv[(i+2)%4];
            if (0<=ny && ny<R && 0<=nx && nx<C &&
                grid[ny][nx]=='#' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            cin >> grid[i][j];
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (grid[i][j]=='#' && !visited[i][j]) {
                cnt++;
                BFS(i, j);
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}