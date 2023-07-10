#include <iostream>
using namespace std;

int main() {
    int input, pprev, prv, cur, max_len=0, max_num;
    cin >> input;
    for (int i=input; i>=0; i--) {
        int cnt=2;
        pprev = input;
        prv = i;
        cur = pprev - prv;
        while (cur>=0) {
            pprev = prv;
            prv = cur;
            cnt++;
            cur = pprev - prv;
        }
        if (cnt>max_len) {
            max_len = cnt;
            max_num = i;
        }
    }
    cout << max_len << '\n';
    pprev = input;
    prv = max_num;
    cout << input << ' ' << max_num << ' ';
    cur = pprev - prv;
    while (cur>=0) {
        cout << cur << ' ';
        pprev = prv;
        prv = cur;
        cur = pprev - prv;
    }
    return 0;
}