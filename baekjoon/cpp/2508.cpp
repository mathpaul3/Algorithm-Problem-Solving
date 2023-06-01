#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int r, c, candy=0;
        char box[400][400]={0,};
        cin >> r >> c;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin >> box[i][j];
                if (box[i][j]=='<' && j>1 && box[i][j-1]=='o' && box[i][j-2]=='>') {
                    candy++;
                }
            }
        }

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (box[i][j]=='^' && i>1 && box[i-1][j]=='o' && box[i-2][j]=='v') {
                    candy++;
                }
            }
        }
        cout << candy << '\n';
    }
    return 0;
}