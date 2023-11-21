#include <iostream>
using namespace std;

int N, M, mv[4]={0,0,-1,1};
char board[50][50]={0,};
short dp[50][50]={0,};
bool visited[50][50]={0,};

int DFS(int i, int j) {
    int left = 0, num = board[i][j]-'0';
    visited[i][j] = true;
    for (int d=0; d<4; d++) {
        int y=i+mv[d]*num, x=j+mv[(d+2)%4]*num;
        if (0>y || y>=N || 0>x || x>=M) continue;
        if (board[y][x]=='H') continue;
        if (visited[y][x]) return -1;
        int tmp;
        if (dp[y][x]) tmp = dp[y][x];
        else tmp = DFS(y, x);
        if (tmp == -1) return -1;
        if (left < tmp) left = tmp;
    }
    visited[i][j] = false;
    dp[i][j] = left + 1;
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    
    cout << DFS(0,0) << '\n';
    return 0;
}