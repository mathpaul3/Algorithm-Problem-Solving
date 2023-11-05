#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T=1;
    string cur, prv, nxt;
    while (1) {
        cin >> cur;
        if (cur=="0") return 0;
        while (1) {
            prv = "";
            for (int i=0; i<cur.size(); i+=2) {
                int repeat = cur[i]-'0';
                while (repeat--) prv += cur[i+1];
            }
            nxt = "";
            int cnt=1;
            for (int i=1; i<prv.size(); i++) {
                if (prv[i-1]==prv[i]) cnt++;
                else {
                    nxt += (char)(cnt+'0');
                    nxt += (char)prv[i-1];
                    cnt = 1;
                }
            }
            nxt += (char)(cnt+'0');
            nxt += prv[prv.size()-1];
            if (nxt != cur) { prv = cur; break; }
            if (prv.size()%2 || prv==cur) break;

            cur = prv;
        }
        cout << "Test " << T++ << ": " << prv << '\n';
    }
    return 0;
}