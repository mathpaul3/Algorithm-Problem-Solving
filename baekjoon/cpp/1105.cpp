#include <iostream>
using namespace std;

int main() {
    string L, R;
    cin >> L >> R;
    if (L.size()<R.size()) {
        cout << 0 << '\n';
        return 0;
    }
    int cnt=0;
    for (int i=0; i<L.size(); i++) {
        if (L[i]==R[i]) {
            if (L[i]=='8') cnt++;
        } else break;
    }
    cout << cnt << '\n';
    return 0;
}