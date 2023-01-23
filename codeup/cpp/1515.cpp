#include <iostream>
using namespace std;

int cur[27][27]={0,}, nxt[27][27]={0,};
int dx[8]={-1, 0, 1, 1, 1, 0, -1, -1}, dy[8]={-1, -1, -1, 0, 1, 1, 1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i=1; i<26; i++)
        for (int j=1; j<26; j++)
            cin >> cur[i][j];
    
    for (int i=1; i<26; i++) {
        for (int j=1; j<26; j++) {
            int cnt=0;
            for (int k=0; k<8; k++)
                if (cur[i+dy[k]][j+dx[k]]) cnt++;
            if (cur[i][j]) {
                if (cnt<2 || cnt>3) nxt[i][j] = 0;
                else nxt[i][j] = 1;
            } else if (cnt == 3) nxt[i][j] = 1;
        }
    }

    for (int i=1; i<26; i++) {
        for (int j=1; j<26; j++)
            cout << nxt[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}