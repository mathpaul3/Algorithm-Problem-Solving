#include <iostream>
using namespace std;

char puzzle[20][20]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string ans="zzzzzzzzzzzzzzzzzzzzz";
    int R, C;
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> puzzle[i][j];
        }
    }

    for (int i=0; i<R; i++) {
        string tmp="";
        for (int j=0; j<C; j++) {
            if (puzzle[i][j]!='#') {
                tmp += puzzle[i][j];
            } else {
                if (tmp.size()>1 && ans>tmp) {
                    ans = tmp;
                }
                tmp = "";
            }
        }
        if (tmp.size()>1 && ans>tmp)
            ans = tmp;
    }

    for (int i=0; i<C; i++) {
        string tmp="";
        for (int j=0; j<R; j++) {
            if (puzzle[j][i]!='#') {
                tmp += puzzle[j][i];
            } else {
                if (tmp.size()>1 && ans>tmp) {
                    ans = tmp;
                }
                tmp = "";
            }
        }
        if (tmp.size()>1 && ans>tmp)
            ans = tmp;
    }

    cout << ans << '\n';

    return 0;
}