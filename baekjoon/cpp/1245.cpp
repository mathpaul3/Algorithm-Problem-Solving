#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt=0, farm[100][70]={0,}, mv[8]={0,1,1,1,0,-1,-1,-1};
bool visited[100][70]={0,};

bool check(int i, int j) {
    queue<pair<int,int> > q;
    bool flag = true;
    q.push(make_pair(i, j));
    visited[i][j] = true;
    while (!q.empty()) {
        int y=q.front().first, x=q.front().second;
        q.pop();
        for (int a=0; a<8; a++) {
            int yy=y+mv[a], xx=x+mv[(a+2)%8];
            if (0<=yy && yy<N && 0<=xx && xx<M && farm[yy][xx] && !visited[yy][xx]) {
                if (farm[y][x]>=farm[yy][xx]) {
                    q.push(make_pair(yy, xx));
                    visited[yy][xx] = true;
                } else if (farm[y][x]==farm[i][j])
                    flag = false;
            }
        }
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N ;i++)
        for (int j=0; j<M; j++)
            cin >> farm[i][j];
    
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (farm[i][j] && !visited[i][j] && check(i, j))
                cnt++;
    cout << cnt << '\n';
    return 0;
}