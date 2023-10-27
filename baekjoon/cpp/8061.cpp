#include <iostream>
#include <queue>
using namespace std;

int n, m, d=1, mv[4]={0,0,1,-1}, dist[200][200];
char bit;
bool bitmap[200][200];
queue<pair<int,int> > q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> bit;
            if (bit=='1') {
                q.push(make_pair(i, j));
                bitmap[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        int sz = q.size();
        for (int pixel=0; pixel<sz; pixel++) {
            int i=q.front().first, j=q.front().second;
            q.pop();
            for (int a=0; a<4; a++) {
                int y=i+mv[a], x=j+mv[(a+2)%4];
                if (0>y || n<y || 0>x || m<x) continue;
                if (bitmap[y][x]) continue;
                bitmap[y][x] = true;
                dist[y][x] = d;
                q.push(make_pair(y, x));
            }
        }
        d++;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cout << dist[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}