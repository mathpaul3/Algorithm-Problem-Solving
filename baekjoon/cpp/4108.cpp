#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int R, C, mv[8]={1,1,1,0,-1,-1,-1,0};

    while (cin >> R >> C) {
        if (!R && !C) break;
        char ground, mine[100][100]={0,};

        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin >> ground;
                if (ground!='*') continue;
                mine[i][j] = '*';
                for (int k=0; k<8; k++) {
                    int ii=i+mv[k], jj=j+mv[(k+2)%8];
                    if (0<=ii && ii<R && 0<=jj && jj<C && mine[ii][jj]!='*') mine[ii][jj]++;
                }
            }
        }
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (mine[i][j]=='*') cout << '*';
                else cout << (int)mine[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}