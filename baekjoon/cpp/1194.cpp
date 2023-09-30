#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, movement=0, mv[4]={0,0,1,-1};
char maze[50][50]={0,};
bool visited[127][50][50]={0,}; // key, y, x
queue<tuple<int,int,int> > q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> maze[i][j];
            if (maze[i][j]=='0') {
                q.push(make_tuple(0, i, j));
                visited[0][i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int sz = q.size();
        movement++;
        for (int i=0; i<sz; i++) {
            int key, y, x;
            tie(key, y, x) = q.front(); q.pop();
            for (int j=0; j<4; j++) {
                int new_key=key, yy=y+mv[j], xx=x+mv[(j+2)%4];
                if (0>yy || N<=yy || 0>xx || M<=xx) continue;
                if (maze[yy][xx]=='#') continue;
                
                if (maze[yy][xx]=='1') {
                    cout << movement << '\n';
                    return 0;
                }

                if ('A'<=maze[yy][xx] && maze[yy][xx]<='F') {
                    if (new_key & (1 << (maze[yy][xx]-'A')))
                        if (!visited[new_key][yy][xx])
                            q.push(make_tuple(new_key, yy, xx));
                }

                else {
                    if ('a'<=maze[yy][xx] && maze[yy][xx]<='f')
                        new_key = key | (1 << (maze[yy][xx]-'a'));
                    if (!visited[new_key][yy][xx])
                        q.push(make_tuple(new_key, yy, xx));
                }
                visited[new_key][yy][xx] = true;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}