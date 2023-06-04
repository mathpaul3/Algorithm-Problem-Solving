#include <iostream>
#include <set>
using namespace std;

int board[5][5]={0,}, mv[4]={0,0,-1,1};
set<int> s;

void DFS(int i, int j, int depth, int num) {
    if (depth == 5) {
        if (s.find(num)==s.end()) s.insert(num);
        return;
    }
    for (int a=0; a<4; a++) {
        int y=i+mv[a], x=j+mv[(a+2)%4];
        if (0<=y && y<5 && 0<=x && x<5) {
            DFS(y, x, depth+1, num*10+board[y][x]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            DFS(i, j, 0, board[i][j]);
        }
    }

    cout << s.size() << '\n';
    return 0;
}