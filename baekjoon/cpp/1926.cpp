#include <iostream>
#include <queue>
using namespace std;

int n, m, mv[4]={0,0,-1,1}, cnt=0, largest=0;
bool paper[500][500]={0,};

void BFS(int i, int j) {
    queue<pair<int,int> > q;
    int drawing=1;
    q.push(make_pair(i, j));
    paper[i][j] = false;
    while (!q.empty()) {
        int y=q.front().first, x=q.front().second;
        q.pop();
        for (int a=0; a<4; a++) {
            int yy=y+mv[a], xx=x+mv[(a+2)%4];
            if (0<=yy && yy<n && 0<=xx && xx<m && paper[yy][xx]) {
                paper[yy][xx] = false;
                q.push(make_pair(yy, xx));
                drawing++;
            }
        }
    }
    if (largest<drawing) largest = drawing;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> paper[i][j];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (paper[i][j]) {
                cnt++;
                BFS(i, j);
            }
        }
    }
    cout << cnt << '\n' << largest << '\n';
    return 0;
}