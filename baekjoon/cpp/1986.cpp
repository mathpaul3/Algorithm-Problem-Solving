#include <iostream>
using namespace std;

int n, m, q, k, p, r, c;
int qmv[8]={1,1,1,0,-1,-1,-1,0},
kmv[8]={2,1,-1,-2,-2,-1,1,2};
pair<int,int> piece[200];
char board[1001][1001]={0,};

void queen(int r, int c) {
    int mask=0x000000FF, cnt=1;
    while (mask) {
        for (int i=0; i<8; i++) {
            int y=r+qmv[i]*cnt, x=c+qmv[(i+2)%8]*cnt;
            if (((mask&(1<<i))==(1<<i)) && 0<y && y<=n && 0<x && x<=m) {
                if (!board[y][x]) board[y][x] = '.';
                else if (board[y][x]!='.') mask -= (1<<i);
            } else if ((mask&(1<<i)) == (1<<i)) mask -= (1<<i);
        }
        cnt++;
    }
}

void knight(int r, int c) {
    for (int i=0; i<8; i++) {
        int y=r+kmv[i], x=c+kmv[(i+6)%8];
        if (0<y && y<=n && 0<x && x<=m && !board[y][x]) board[y][x] = '.';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> piece[i].first >> piece[i].second;
        board[piece[i].first][piece[i].second] = 'Q';
    }
    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> piece[q+i].first >> piece[q+i].second;
        board[piece[q+i].first][piece[q+i].second] = 'K';
    }
    cin >> p;
    for (int i=0; i<p; i++) {
        cin >> r >> c;
        board[r][c] = 'P';
    }
    for (int i=0; i<q+k; i++) {
        r=piece[i].first, c=piece[i].second;
        if (i<q) queen(r, c);
        else knight(r, c);
    }

    int cnt=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cnt += !board[i][j];
    cout << cnt << '\n';
    return 0;
}