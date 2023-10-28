#include <iostream>
#include <queue>
using namespace std;

bool is_dead;
int n, m, r, direction, cury, curx, cnt=0, mv[4]={-1,0,1, 0};
char command, map[1000][1000];
queue<pair<int,int> > snake;

bool move() {
    if (command=='L') direction = (direction+3)%4;
    else if (command=='P') direction = (direction+1)%4;
    cury += mv[direction]; curx += mv[(direction+1)%4];
    if (0>cury || n<=cury || 0>curx || m<=curx) return false;
    if (map[cury][curx]=='W') return false;
    snake.push(make_pair(cury, curx));
    if (!(map[cury][curx]=='J')) {
        map[snake.front().first][snake.front().second] = '.';
        snake.pop();
    }
    map[cury][curx] = 'W';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> r;
    cin >> command;
    if (command=='N') direction = 0;
    else if (command=='E') direction = 1;
    else if (command=='S') direction = 2;
    else if (command=='W') direction = 3;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j]=='W') {
                cury = i, curx = j;
                snake.push(make_pair(i, j));
            }
        }
    }
    while (r--) {
        cin >> command;
        if (is_dead) continue;
        else if (!move()) is_dead = true;
        cnt++;
    }
    if (is_dead) cout << cnt << '\n';
    else cout << "OK\n";
    
    return 0;
}