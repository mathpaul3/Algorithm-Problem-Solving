#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int R, C;
    char ranch[500][500]={0,};
    int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
    queue<pair<int,int> > sheep;
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> ranch[i][j];
            if (ranch[i][j] == 'S')
                sheep.push(make_pair(i, j));
        }
    }
    bool is_wolf=false;
    while (!sheep.empty()) {
        int y=sheep.front().first, x=sheep.front().second;
        sheep.pop();
        for (int i=0; i<4; i++) {
            int yy = y+dy[i], xx = x+dx[i];
            if (0<=yy && yy<R && 0<=xx && xx<C && (ranch[yy][xx]=='W')) {is_wolf=true; break;}
        }
        if (is_wolf) break;
    }
    if (is_wolf) cout << 0 << '\n';
    else {
        cout << 1 << '\n';
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++)
                cout << (ranch[i][j]=='.'?'D':ranch[i][j]);
            cout << '\n';
        }
    }

    return 0;
}