#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, M;
    bool flag=false, nxt_flag=false;
    string prv, cur, nxt;
    char prvc=0, nxtc=0;
    set<string> s;
    cin >> N;
    while (N--) {
        cin >> cur;
        s.insert(cur);
        if (!flag) {
            if (cur == "?") {
                flag = true;
                prvc = prv[prv.size()-1];
            }
            prv = cur;
        }
        else if (!nxt_flag) {
            nxt_flag = true;
            nxtc = cur[0];
        }
    }
    cin >> M;
    while (M--) {
        cin >> cur;
        if (s.find(cur)!=s.end()) continue;
        if (prvc==0 && nxtc==0) {
            cout << cur << '\n';
        } else if (prvc==0) {
            if (cur[cur.size()-1]==nxtc)
                cout << cur << '\n';    
        } else if (nxtc==0) {
            if (cur[0]==prvc)
                cout << cur << '\n';
        } else {
            if (cur[0]==prvc && cur[cur.size()-1]==nxtc)
                cout << cur << '\n';
        }
    }
    return 0;
}