#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string> *cards, bool eof) {
    int cnt = 0;
    bool global_flag = false;
    cout << "CARDS: ";
    for (int i=0; i<(*cards).size(); i++) {
        cout << ' ' << (*cards)[i];
    }
    cout << '\n';
    for (int i=0; i<(*cards).size()-2; i++) {
        for (int j=i+1; j<(*cards).size()-1; j++) {
            for (int k=j+1; k<(*cards).size(); k++) {
                bool flag = true;
                for (int l=0; l<4; l++) {
                    if (!((*cards)[i][l]==(*cards)[j][l] &&
                        (*cards)[j][l]==(*cards)[k][l] &&
                        (*cards)[k][l]==(*cards)[i][l])
                        &&
                        !((*cards)[i][l]!=(*cards)[j][l] &&
                        (*cards)[j][l]!=(*cards)[k][l] &&
                        (*cards)[k][l]!=(*cards)[i][l])
                    ) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    global_flag = true;
                    cnt += 1;
                    if (cnt == 1) cout << "SETS:   ";
                    else cout << "        ";
                    cout << cnt << ".  ";
                    cout << (*cards)[i] << ' ' << (*cards)[j] << ' ' << (*cards)[k] << '\n';
                }
            }
        }
    }
    if (!global_flag) cout << "SETS:   *** None Found ***\n";
    (*cards).clear();
    if (!eof) cout << '\n';
}

int main() {
    vector<string> cards, empty_arr;
    string card;
    while (getline(cin, card)) {
        if (card!="") {
            cards.push_back(card);
            continue;
        }
        solve(&cards, false);
    }
    solve(&cards, true);
    return 0;
}