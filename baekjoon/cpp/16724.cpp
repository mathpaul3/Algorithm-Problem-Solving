#include <iostream>
using namespace std;

int N, M;
char map[1000][1000];

bool explore(int y, int x) {
    if (map[y][x] == 'S') return false;
    if (map[y][x] == 'V') {
        map[y][x] = 'S';
        return true;
    }

    char cur = map[y][x];
    bool result;
    map[y][x] = 'V';
    if (cur == 'D') result = explore(y+1, x);
    else if (cur == 'U') result = explore(y-1, x);
    else if (cur == 'L') result = explore(y, x-1);
    else if (cur == 'R') result = explore(y, x+1);
    map[y][x] = 'S';
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> map[i][j];
    
    int safe_zone = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j] != 'V' && map[i][j] != 'S') {
                if (explore(i, j)) safe_zone++;
            }
        }
    }

    cout << safe_zone << '\n';

    return 0;
}