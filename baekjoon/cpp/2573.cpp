#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int> > q;
int mv[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, ice[300][300]={0,}, year=0;
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> ice[i][j];
            if (ice[i][j] != 0) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        queue<pair<int,int> > group;
        int melt[300][300] = {0,};

        int sz = q.size();
        for (int a=0; a<sz; a++) {
            int i=q.front().first, j=q.front().second; q.pop();
            for (int b=0; b<4; b++) {
                int y=i+mv[b], x=j+mv[(b+2)%4];
                if (0<=y && y<N && 0<=x && x<M && !ice[y][x]) {
                    melt[i][j]--;
                }
            }
            if (ice[i][j]+melt[i][j]>0) {
                q.push(make_pair(i, j));
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                ice[i][j] = (ice[i][j]+melt[i][j]>0 ? ice[i][j]+melt[i][j] : 0);
            }
        }
        if (q.empty()) { cout << 0 << '\n'; return 0; }
        sz = q.size();
        int visit[300][300] = {0,}, cnt=1;
        visit[q.front().first][q.front().second] = true;
        group.push(make_pair(q.front().first, q.front().second));
        
        while (!group.empty()) {
            int i=group.front().first, j=group.front().second;
            group.pop();
            for (int a=0; a<4; a++) {
                int y=i+mv[a], x=j+mv[(a+2)%4];
                if (ice[y][x] && !visit[y][x]) {
                    visit[y][x] = true;
                    cnt++;
                    group.push(make_pair(y, x));
                }
            }
        }
        year++;
        if (cnt != sz) {
            cout << year << '\n';
            return 0;
        }
    }

    return 0;
}