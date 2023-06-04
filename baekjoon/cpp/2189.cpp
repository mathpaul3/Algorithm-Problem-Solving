#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T=0;
    while (true) {
        int n, tmp, row[8]={0,}, col[8]={0,}, diag_up=0, diag_down=0;
        bool not_magic=false, strongly_magic=true, magically_magic=true;
        set<int> s; // check num
        cin >> n;
        if (!n) break;
        T++;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> tmp;
                row[i] += tmp;
                col[j] += tmp;
                if (i==j) diag_down += tmp;
                if (n-i-1==j) diag_up += tmp;
                // distinct
                if (s.find(tmp)==s.end()) s.insert(tmp);
                else strongly_magic = false;
            }
        }

        // row, col
        for (int i=1; i<n; i++) {
            if (row[i]!=col[0] || col[i]!=col[0]) {
                not_magic = true;
                break;
            }
        }
        if (not_magic) {
            cout << "Square " << T << ": Not a Magick Square\n";
            continue;
        }

        // diagonal
        if (diag_down!=col[0] || diag_up!=col[0]) {
            cout << "Square " << T << ": Semi-Magick Square\n";
            continue;
        }

        // consecutive
        int prev = (*s.begin())-1;
        for (set<int>::iterator it = s.begin(); it!=s.end(); it++) {
            if ((*it) != prev+1) {
                magically_magic = false;
                break;
            }
            prev = (*it);
        }

        if (strongly_magic && magically_magic) {
            cout << "Square " << T << ": Magically-Magick Square\n";
            continue;
        }
        if (strongly_magic) {
            cout << "Square " << T << ": Strongly-Magick Square\n";
            continue;
        }
        cout << "Square " << T << ": Weakly-Magick Square\n";
    }
    return 0;
}