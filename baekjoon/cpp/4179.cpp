#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int R, C, mv[4]={0, 0, 1, -1}, time=0;
    char map[1000][1000]={0,};
    bool visit[1000][1000]={0,};
    queue<pair<int,int> > q, fire;
    cin >> R >> C;
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> map[i][j];
            if (map[i][j]=='J') {
                map[i][j] = '.';
                visit[i][j] = true;
                q.push(make_pair(i, j));
            } else if (map[i][j]=='F') {
                fire.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        time++;
        int sz = fire.size();
        for (int a=0; a<sz; a++) {
            int i=fire.front().first, j=fire.front().second;
            fire.pop();
            for (int k=0; k<4; k++) {
                int y=i+mv[k], x=j+mv[(k+2)%4];
                if (0<=y && y<R && 0<=x && x<C && map[y][x]=='.') {
                    map[y][x] = 'F';
                    fire.push(make_pair(y, x));
                }
            }
        }

        sz = q.size();
        for (int a=0; a<sz; a++) {
            int i=q.front().first, j=q.front().second;
            q.pop();
            for (int b=0; b<4; b++) {
                int y=i+mv[b], x=j+mv[(b+2)%4];
                if (0<=y && y<R && 0<=x && x<C) {
                    if (map[y][x]=='.' && !visit[y][x]) {
                        q.push(make_pair(y, x));
                        visit[y][x] = true;
                    }
                } else {
                    cout << time << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}