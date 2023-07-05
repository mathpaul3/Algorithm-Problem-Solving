#include <iostream>
#include <queue>
using namespace std;

int X, Y, N, Ai, Bi, cnt=0;
int mv[4]={0,0,-1,1};
bool puddle[1001][1001]={0,}, visited[1001][1001]={0,};
queue<pair<int,int> > q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> X >> Y >> N;
    X += 500; Y += 500;
    while (N--) {
        cin >> Ai >> Bi;
        puddle[Bi+500][Ai+500] = true;
    }
    q.push(make_pair(500,500));
    visited[500][500] = true;
    while (!q.empty()) {
        int sz = q.size();
        cnt++;
        for (int i=0; i<sz; i++) {
            for (int j=0; j<4; j++) {
                int y=q.front().first+mv[j], x=q.front().second+mv[(j+2)%4];
                if (y==Y && x==X) {\
                    cout << cnt << '\n';
                    return 0;
                }
                if (!puddle[y][x] && !visited[y][x]) {
                    q.push(make_pair(y, x));
                    visited[y][x] = true;
                }
            }
            q.pop();
        }
    }
    return 0;
}