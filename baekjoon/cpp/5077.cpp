#include <iostream>
using namespace std;

int scenarios, Li, Ci, Lm, Cm, cnt;
char rig[12][12]={0,}, map[35][35]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> scenarios;
    while (scenarios--) {
        cnt = 0;
        cin >> Li >> Ci;
        for (int i=0; i<Li; i++)
            for (int j=0; j<Ci; j++)
                cin >> rig[i][j];
        
        cin >> Lm >> Cm;
        for (int i=0; i<Lm; i++)
            for (int j=0; j<Cm; j++)
                cin >> map[i][j];
        
        for (int i=0; i<Lm-Li+1; i++) {
            for (int j=0; j<Cm-Ci+1; j++) {
                bool is_same = true;
                for (int k=0; k<Li; k++) {
                    for (int l=0; l<Ci; l++) {
                        if (map[i+k][j+l]!=rig[k][l]) {
                            is_same = false;
                            break;
                        }
                    }
                    if (!is_same) break;
                }
                cnt += is_same;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}