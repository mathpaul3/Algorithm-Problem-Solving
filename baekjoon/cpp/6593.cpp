#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int L, R, C;
    while (cin >> L >> R >> C) {
        if (!L && !R && !C) break;
        int minutes=0, mv[6]={0,0,0,0,1,-1};
        bool flag=false, visited[30][30][30]={0,};
        char building[30][30][30]={0,};
        queue<tuple<int,int,int> > q;
        for (int i=0; i<L; i++) {
            for (int j=0; j<R; j++) {
                for (int k=0; k<C; k++) {
                    cin >> building[i][j][k];
                    if (building[i][j][k]=='S')
                        q.push(make_tuple(i, j, k));
                }
            }
        }
        while (!q.empty()) {
            int sz = q.size();
            minutes++;
            for (int a=0; a<sz; a++) {
                int i, j, k;
                tie(i, j, k) = q.front(); q.pop();
                for (int b=0; b<6; b++) {
                    int z=i+mv[b], y=j+mv[(b+2)%6], x=k+mv[(b+4)%6];
                    if (0<=z && z<L && 0<=y && y<R && 0<=x && x<C) {
                        if (building[z][y][x]=='E') {
                            cout << "Escaped in " << minutes << " minute(s).\n";
                            flag = true;
                            break;
                        }
                        if (building[z][y][x]!='#' && !visited[z][y][x]) {
                            visited[z][y][x] = true;
                            q.push(make_tuple(z, y, x));
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (!flag) cout << "Trapped!\n";
    }
    return 0;
}