#include <iostream>
#include <queue>
using namespace std;

int T, mv[4]={1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        char box[3][3]={0,};
        bool visited[3][3]={0,};
        queue<pair<int,int> > q;
        priority_queue<int> pq;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                cin >> box[i][j];

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (box[i][j]=='O' && !visited[i][j]) {
                    int cnt=0;
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        int fi = q.front().first, fj = q.front().second; q.pop();
                        cnt++;
                        for (int c=0; c<4; c++) {
                            int y=fi+mv[c], x=fj+mv[(c+2)%4];
                            if (0<=y && y<3 && 0<=x && x<3 && box[y][x]=='O' && !visited[y][x]) {
                                q.push(make_pair(y, x));
                                visited[y][x] = true;
                            }
                        }
                    }
                    pq.push(-cnt);
                }
            }
        }
        bool good=true;
        int connection, tmp;
        cin >> connection;
        if (connection!=pq.size()) good = false;
        while (connection--) {
            cin >> tmp;
            if (!pq.empty() && -pq.top()==tmp) pq.pop();
            else good = false;
        }

        cout << good << '\n';
    }
    return 0;
}