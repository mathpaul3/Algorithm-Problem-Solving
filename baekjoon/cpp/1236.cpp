#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, c=0, r=0;
    char cell;
    bool col[50]={0,}, row[50]={0,};
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> cell;
            if (cell=='X') {
                if (!col[j]) {
                    col[j] = true;
                    c++;
                }
                if (!row[i]) {
                    row[i] = true;
                    r++;
                }
            }
        }
    }
    cout << (M-c<N-r ? N-r : M-c) << '\n';
    return 0;
}