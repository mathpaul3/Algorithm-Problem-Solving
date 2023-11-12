#include <iostream>
#define DIV 1000000007
using namespace std;

int main() {
    int T, C, V, L;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> C >> V >> L;
        long long cases[15][2]={0,};
        cases[0][0] = C;
        cases[0][1] = V;
        for (int i=1; i<L; i++) {
            cases[i][0] = cases[i-1][1]*C%DIV;
            cases[i][1] = (cases[i-1][0]*V%DIV + cases[i-1][1]*V%DIV)%DIV;
        }
        cout << "Case #" << t << ": " << cases[L-1][1] << '\n';
    }
    return 0;
}