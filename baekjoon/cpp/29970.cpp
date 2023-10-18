#include <iostream>
using namespace std;

int N, prv, cur, rise=0, max_rise=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> prv;
    while (--N) {
        cin >> cur;
        if (prv<cur) {
            rise += cur-prv;
            if (rise>max_rise) max_rise = rise;
        }
        else rise = 0;
        prv = cur;
    }
    cout << max_rise << '\n';
    return 0;
}