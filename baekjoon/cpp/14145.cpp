#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int R, S, mv[4]={0,0,-1,1}, num[50][50]={0,};
char wheat[50][50]={0,}, visited[50][50]={0,};
pair<int,int> map[50][50];
priority_queue<tuple<int,int,int> > pq;

void BFS(int y, int x) {
    queue<pair<int,int> > q;
    int cnt=1;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    map[y][x] = make_pair(y, x);
    while (!q.empty()) {
        int Y=q.front().first, X=q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int yy = Y+mv[i], xx = X+mv[(i+2)%4];
            if (0<=yy && yy<R && 0<=xx && xx<S && !visited[yy][xx] && wheat[yy][xx]) {
                visited[yy][xx] = true;
                map[yy][xx] = make_pair(y, x);
                cnt++;
                q.push(make_pair(yy, xx));
            }
        }
    }
    pq.push(make_tuple(-cnt, y, x));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> S;
    for (int i=0; i<R; i++) {
        for (int j=0; j<S; j++) {
            cin >> wheat[i][j];
            wheat[i][j] = wheat[i][j]-'0';
            map[i][j] = make_pair(i, j);
        }
    }

    for (int i=0; i<R; i++)
        for (int j=0; j<S; j++)
            if (wheat[i][j] && !visited[i][j])
                BFS(i, j);

    int n = 1;
    while (!pq.empty()) {
        int topy = get<1>(pq.top()), topx = get<2>(pq.top());
        num[topy][topx] = n++;
        pq.pop();
    }
    for (int i=0; i<R; i++) {
        for (int j=0; j<S; j++) 
            cout << num[map[i][j].first][map[i][j].second];
        cout << '\n';
    }
    return 0;
}