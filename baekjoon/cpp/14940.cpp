#include <iostream>
#include <queue>
using namespace std;

int n, m, mv[4]={0,0,1,-1}, dist[1000][1000];
char map[1000][1000];
bool visited[1000][1000];
queue<pair<int,int> > q;

void BFS() {
    int d = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int a=0; a<sz; a++) {
            int y=q.front().first, x=q.front().second;
            q.pop();
            for (int b=0; b<4; b++) {
                int yy=y+mv[b], xx=x+mv[(b+2)%4];
                if (yy<0 || yy>=n || xx<0 || xx>=m) continue;
                if (visited[yy][xx] || map[yy][xx]=='0') continue;
                visited[yy][xx] = true;
                dist[yy][xx] = d;
                q.push(make_pair(yy, xx));
            }
        }
        d++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j]=='2') {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
    BFS();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!dist[i][j]) cout << (map[i][j]=='1' ? -1 : 0);
            else cout << dist[i][j];
            cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}