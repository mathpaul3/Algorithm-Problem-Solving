#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, mv[8]={0,1, 1, 1, 0, -1, -1, -1};
    char tmp, map[1000][1000]={0,};
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> tmp;
            if (tmp!='.') {
                map[i][j] = 100;
                for (int k=0; k<8; k++) {
                    short y=i+mv[k], x=j+mv[(k+2)%8];
                    if (0<=y && y<N && 0<=x && x<N && map[y][x]!=100)
                        map[y][x] += tmp-'0';
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j]==100) cout << '*';
            else if (map[i][j]>9) cout << 'M';
            else cout << (int)map[i][j];
        }
        cout << '\n';
    }
    return 0;
}