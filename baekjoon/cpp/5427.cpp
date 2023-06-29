#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, w, h, mv[4]={0, 0, 1, -1};
    cin >> T;
    while (T--) {
        int time = 0;
        char map[1000][1000]={0,};
        bool visit[1000][1000]={0,}, escape=false;
        queue<pair<int,int> > q, fire;
        cin >> w >> h;
        
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin >> map[i][j];
                if (map[i][j]=='@') {
                    map[i][j] = '.';
                    visit[i][j] = true;
                    q.push(make_pair(i, j));
                } else if (map[i][j]=='*') {
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
                    if (0<=y && y<h && 0<=x && x<w && map[y][x]=='.') {
                        map[y][x] = '*';
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
                    if (0<=y && y<h && 0<=x && x<w) {
                        if (map[y][x]=='.' && !visit[y][x]) {
                            q.push(make_pair(y, x));
                            visit[y][x] = true;
                        }
                    } else {
                        cout << time << '\n';
                        escape = true;
                        break;
                    }
                }
                if (escape) break;
            }
            if (escape) break;
        }
        if (escape) continue;
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}