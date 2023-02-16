#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int len[3]={0,};
    while (true) {
        bool fin=true;
        for (int i=0; i<3; i++) {
            cin >> len[i];
            if (len[i]) fin=false;
            len[i] *= len[i];
        }
        if (fin) break;
        sort(len, len+3);
        cout << ((len[0]+len[1] == len[2]) ? "right" : "wrong") << '\n';
    }
    return 0;
}