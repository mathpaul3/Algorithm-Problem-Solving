#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, n, tmpn;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int p[6]={0,}, diff[51]={0,};
        cin >> n;
        tmpn = n;
        for (int i=0; i<=n; i++)
            cin >> diff[i];
        for (int i=0; i<n; i++) {
            p[i] = diff[0];
            for (int i=0; i<tmpn; i++)
                diff[i] = diff[i+1]-diff[i];
            tmpn--;
        }
        for (int i=1; i<=50; i++) diff[i] = diff[0];
        for (int i=n-1; i>=0; i--) {
            int curdiff = diff[0], nxtdiff;
            diff[0] = p[i];
            for (int j=1; j<=50; j++) {
                nxtdiff = diff[j];
                diff[j] = diff[j-1] + curdiff;
                curdiff = nxtdiff;
            }
        }
        cout << "Case #" << t << ": " << diff[50] << '\n';
    }
    return 0;
}