#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int M, N=1, inc=1, dec=1, inc_max=1, dec_max=1, cur, prv;
    cin >> M;
    cin >> prv;
    while (--M) {
        cin >> cur;
        if (cur>prv) {
            dec = 1;
            if (++inc>inc_max) inc_max = inc;
        } else if (cur<prv) {
            inc = 1;
            if (++dec>dec_max) dec_max = dec;
        }
        prv = cur;
    }
    cout << (inc_max<dec_max ? dec_max : inc_max) << '\n';
    return 0;
}