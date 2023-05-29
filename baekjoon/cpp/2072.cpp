#include <iostream>
using namespace std;

char board[20][20]={0,};

bool check_fin(int y, int x) {
    char color = board[y][x];
    // 세로
    int dist=1, cnt=1;
    bool plus=true, minus=true;
    while (true) {
        bool valid=false;
        int i=y+dist, ii=y-dist;
        if (plus && i<20 && board[i][x]==color) {
            cnt++; valid=true;
        } else plus=false;
        if (minus && 0<ii && board[ii][x]==color) {
            cnt++; valid=true;
        } else minus=false;
        if (!valid) break;
        dist++;
    }
    if (cnt==5) return true;
    
    // 가로
    dist=1, cnt=1; plus=true, minus=true;
    while (true) {
        bool valid=false;
        int j=x+dist, jj=x-dist;
        if (plus && j<20 && board[y][j]==color) {
            cnt++; valid=true;
        } else plus=false;
        if (minus && 0<jj && board[y][jj]==color) {
            cnt++; valid=true;
        } else minus=false;
        if (!valid) break;
        dist++;
    }
    if (cnt==5) return true;

    // 하강 대각선
    dist=1, cnt=1; plus=true, minus=true;
    while (true) {
        bool valid=false;
        int i=y+dist, ii=y-dist, j=x+dist, jj=x-dist;
        if (plus && i<20 && j<20 && board[i][j]==color) {
            cnt++; valid=true;
        } else plus=false;
        if (minus && 0<ii && 0<jj && board[ii][jj]==color) {
            cnt++; valid=true;
        } else minus=false;
        if (!valid) break;
        dist++;
    }
    if (cnt==5) return true;

    // 상승 대각선
    dist=1, cnt=1; plus=true, minus=true;
    while (true) {
        bool valid=false;
        int i=y+dist, ii=y-dist, j=x+dist, jj=x-dist;
        if (plus && i<20 && 0<jj && board[i][jj]==color) {
            cnt++; valid=true;
        } else plus=false;
        if (minus && 0<ii && j<20 && board[ii][j]==color) {
            cnt++; valid=true;
        } else minus=false;
        if (!valid) break;
        dist++;
    }
    if (cnt==5) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bool finished=false;
    int N, fin=0, y, x;

    cin >> N;
    while (N--) {
        cin >> y >> x;
        if (finished) continue;
        fin++;
        board[y][x] = (fin%2 ? 'B':'W');
        if (check_fin(y, x)) {
            finished = true;
            cout << fin << '\n';
        }
    }
    if (!finished) cout << -1 << '\n';
    return 0;
}