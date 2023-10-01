#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int> > q;
int mv[8]={1,2,2,1,-1,-2,-2,-1};
bool visited[9][9]={0,};

int main() {
    int sr, sc, er, ec, movement=0;
    cin >> sr >> sc >> er >> ec;
    q.push(make_pair(sr, sc));
    if (sr==er && sc==ec) {
        cout << movement << '\n';
        return 0;
    }
    while (!q.empty()) {
        int sz = q.size();
        movement++;
        for (int i=0; i<sz; i++) {
            int r=q.front().first, c=q.front().second;
            q.pop();
            for (int j=0; j<8; j++) {
                int y=r+mv[j], x=c+mv[(j+2)%8];
                if (0<y && y<9 && 0<x && x<9 && !visited[y][x]) {
                    if (y==er && x==ec) {
                        cout << movement << '\n';
                        return 0;
                    }
                    visited[y][x] = true;
                    q.push(make_pair(y, x));
                }
            }
        }
    }
    return 0;
}