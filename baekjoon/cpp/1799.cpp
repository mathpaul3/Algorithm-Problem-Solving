#include <iostream>
using namespace std;

int N;
int ans[2]={0,};
int r[20]={0,}, l[20]={0,};
bool board[10][10]={0,};

void DFS(int i, int j, int cnt, int color) {
    if (j>=N) {
        i++;
        j = (j%2 ? 0 : 1);
    }
    if (i>=N) { ans[color] = max(ans[color], cnt); return; }
    
    if (board[i][j] && !l[(j-i)+(N-1)] && !r[i+j]) {
        l[(j-i) + (N-1)] = r[i+j] = 1;
        DFS(i, j+2, cnt+1, color);
        l[(j-i) + (N-1)] = r[i+j] = 0;
    }
    DFS(i, j+2, cnt, color);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> board[i][j];

    DFS(0,0,0,0);
    DFS(0,1,0,1);
    cout << ans[0] + ans[1] << '\n';
    return 0;
}