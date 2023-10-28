#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, Hx, Hy, Ex, Ey, D=0, mv[4]={0,0,1,-1};
bool is_broke, maze[1001][1001], visited[1001][1001][2];

void BFS() {
    queue<tuple<int,int,bool> > q;
    visited[Hy][Hx][0] = true;
    q.push(make_tuple(Hy, Hx, 0));
    while (!q.empty()) {
        int sz = q.size();
        for (int a=0; a<sz; a++) {
            tie(Hy, Hx, is_broke) = q.front();
            q.pop();
            for (int b=0; b<4; b++) {
                int y=Hy+mv[b], x=Hx+mv[(b+2)%4];
				bool cur_broke=is_broke;
                if (y<1 || y>N || x<1 || x>M) continue;
                if (visited[y][x][is_broke] || (is_broke && maze[y][x])) continue;
                if (y==Ey && x==Ex) { cout << D+1 << '\n'; return ; }
                if (maze[y][x] || is_broke) {
                    q.push(make_tuple(y, x, 1)); cur_broke=1;
                } else {
                    q.push(make_tuple(y, x, 0));
                }
                visited[y][x][cur_broke] = true;
            }
        }
        D++;
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> Hy >> Hx >> Ey >> Ex;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++) cin >> maze[i][j];
    
    BFS();
    return 0;
}
