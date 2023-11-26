#include <iostream>
using namespace std;

int N;
char b, beer[10][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            cin >> b;
            switch(b) {
                case 'U': beer[N-i][j-1] = 0; break;
                case 'L': beer[N-i][j-1] = 1; break;
                case 'D': beer[N-i][j-1] = 2; break;
                case 'R': beer[N-i][j-1] = 3; break;
            }
        }
    }

    for (int i=N; i>0; i--) {
        for (int j=1; j<=i; j++) {
            if (beer[N-i][j-1]!=0) {
                for (int k=0; k<beer[N-i][j-1]; k++)
                    cout << N-i+1 << ' ' << j << '\n';
                if (i>1) {
                    if (j>1) beer[N-i+1][j-2] = (beer[N-i+1][j-2] + beer[N-i][j-1]) % 4;
                    beer[N-i+1][j-1] = (beer[N-i+1][j-1] + beer[N-i][j-1]) % 4;
                }
                beer[N-i][j-1] = 0;
            }
        }
    }
    return 0;
}