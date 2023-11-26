#include <iostream>
using namespace std;

int M, F;
string DNA_M[20], DNA_F[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> F;
    for (int i=0; i<M; i++) cin >> DNA_M[i];
    for (int i=0; i<F; i++) cin >> DNA_F[i];

    for (int i=0; i<M; i++) {
        for (int j=0; j<F; j++) {
            string mother = DNA_M[i], father = DNA_F[j];
            int cnt=0;
            for (int k=0; k<M; k++) {
                if (i==k) continue;
                bool flag = true;
                for (int l=0; l<mother.size(); l++) {
                    if (DNA_M[k][l]!=mother[l] && DNA_M[k][l]!=father[l])
                    { flag = false; break; }
                }
                cnt += flag;
            }
            for (int k=0; k<F; k++) {
                if (j==k) continue;
                bool flag = true;
                for (int l=0; l<father.size(); l++) {
                    if (DNA_F[k][l]!=mother[l] && DNA_F[k][l]!=father[l])
                    { flag = false; break; }
                }
                cnt += flag;
            }
            cout << cnt << ' ';
        }
        cout << '\n';
    }
    return 0;
}