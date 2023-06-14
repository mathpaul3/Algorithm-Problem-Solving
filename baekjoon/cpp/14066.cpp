#include <iostream>
using namespace std;

int m, n;
char kocka[6][7]={
    {'+', '-', '-', '-', '+', 0, 0},
    {'|', ' ', ' ', ' ', '|', '/', 0},
    {'|', ' ', ' ', ' ', '|', ' ', '+'},
    {'+', '-', '-', '-', '+', ' ', '|'},
    {0, '/', ' ', ' ', ' ', '/', '|'},
    {0, 0, '+', '-', '-', '-', '+'},
}, result[255][306]={0,};


void napraviti_kocku(int y, int x) {
    for (int i=0; i<6; i++) {
        for (int j=0; j<7; j++) {
            if (!result[y+i][x+j]) {
                result[y+i][x+j] = kocka[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int arr[50][50]={0,};
    int max_i=0, max_j=0;
    cin >> m >> n;

    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> arr[i][j];

    for (int i=m-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            for (int k=arr[i][j]-1; k>=0; k--) {
                int y=(m-i-1)*2+k*3, x=(m-i-1)*2+j*4;
                if (max_i<y) max_i = y;
                if (max_j<x) max_j = x;
                napraviti_kocku(y, x);
            }
        }
    }
    max_i += 6;
    max_j += 7;

    for (int i=max_i-1; i>=0; i--) {
        for (int j=0; j<max_j; j++) {
            cout << (result[i][j] ? result[i][j] : '.');
        }
        cout << '\n';
    }
    
    return 0;
}