#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        bool is_correct = true, diag[6]={0,}, rev_diag[6]={0,}, col[6][6]={0,};
        int sudoku;
        for (int i=0; i<6; i++) {
            bool row[6]={0,};
            for (int j=0; j<6; j++) {
                cin >> sudoku;
                if (!is_correct || 1>sudoku || sudoku>6) {is_correct=false; continue;}
                sudoku--;
                if (i==j) diag[sudoku] = true;
                if (i==5-j) rev_diag[sudoku] = true;
                row[sudoku] = true;
                col[j][sudoku] = true;
            }
            if (!is_correct) continue;
            for (int j=0; j<6; j++)
                if (!row[j]) is_correct = false;
        }
        for (int i=0; i<6; i++) {
            for (int j=0; j<6; j++)
                if (!col[i][j]) is_correct = false;
            if (!diag[i]) is_correct = false;
            if (!rev_diag[i]) is_correct = false;
        }
        cout << "Case#" << t << ": " << is_correct << '\n';
    }
    return 0;
}