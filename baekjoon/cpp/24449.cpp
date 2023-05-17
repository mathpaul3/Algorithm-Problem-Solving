#include <iostream>
#include <queue>
using namespace std;

int H, W;
int mv[4]={0,0,-1,1};
char carpet[500][500]={0,};

int BFS() {
    int cnt=0;
    bool visit[500][500]={0,};
    queue<pair<int,int> > q;

    q.push(make_pair(0, 0));

    while (!q.empty()) {
        cnt++;
        int sz = q.size();
        for (int a=0; a<sz; a++) {
            int i=q.front().first, j=q.front().second;
            char color = carpet[i][j];
            q.pop();
            for (int b=0; b<4; b++) {
                int y=i+mv[b], x=j+mv[(b+2)%4];
                if (0<=y && y<H && 0<=x && x<W && color!=carpet[y][x] && !visit[y][x]) {
                    if (y==H-1 && x==W-1) return cnt;
                    visit[y][x] = true;
                    q.push(make_pair(y, x));
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> H >> W;
    for (int i=0; i<H; i++)
        for (int j=0; j<W; j++)
            cin >> carpet[i][j];

    cout << BFS() << '\n';
    return 0;
}