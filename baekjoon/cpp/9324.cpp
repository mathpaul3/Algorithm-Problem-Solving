#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    string M;
    cin >> T;
    while (T--) {
        cin >> M;
        int sz=M.size(), alpha[26]={0,};
        bool fake = false;
        for (int i=0; i<sz; i++) {
            if (!(++alpha[M[i]-'A']%3)) {
                if (i+1<sz && M[i]==M[i+1]) i++;
                else {
                    fake = true;
                    break;
                }
            }
        }
        cout << (fake ? "FAKE\n" : "OK\n");
    }
    return 0;
}