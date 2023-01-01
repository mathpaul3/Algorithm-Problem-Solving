#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int S=0, K=0, H=0, SK=0, SH=0, KH=0, SKH=0;

void count(string str) {
    if (str == "S") S++;
    else if (str == "K") K++;
    else if (str == "H") H++;
    else if (str == "SK") SK++;
    else if (str == "SH") SH++;
    else if (str == "KH") KH++;
    else if (str == "SKH") SKH++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, p, q, r;
    cin >> N >> p >> q >> r;

    string str = "";
    char prev = ' ';
    while (N--) {
        char cur;
        cin >> cur;
        if (prev == cur) { 
            count(str);
            str = cur;
        } else if (prev == 'S') {
            str += cur;
        } else if (prev == 'K') {
            if (cur == 'S') {
                count(str);
                str = cur;
            } else {
                str += cur;
            }
        } else if (prev == 'H') {
            count(str);
            str = cur;
        } else  {
            str += cur;
        }
        prev = cur;
    }
    count(str);

    int cnt = 0;
    // SKH
    cnt += SKH;

    // SK
    cnt += min(SK, r); r -= min(SK, r);
    // SH
    cnt += min(SH, q); q -= min(SH, q);
    // KH
    cnt += min(KH, p); p -= min(KH, p);

    int M = 0;
    // S
    int mi = min({S, q, r});
    for (int i=0; i<=mi; i++) {
        int t1 = min({K, p, r-i});
        int t2 = min({H, p-t1, q-i});
        int t3 = min({p-t1-t2, q-i-t2, r-i-t1});
        M = max(M, i+t1+t2+t3);
    }
    
    // K
    mi = min({K, p, r});
    for (int i=0; i<=mi; i++) {
        int t1 = min({S, q, r-i});
        int t2 = min({H, p-i, q-t1});
        int t3 = min({p-i-t2, q-t1-t2, r-i-t1});
        M = max(M, i+t1+t2+t3);
    }

    // H
    mi = min({H, p, q});
    for (int i=0; i<=mi; i++) {
        int t1 = min({S, q-i, r});
        int t2 = min({H, p-i, r-t1});
        int t3 = min({p-i-t2, q-i-t1, r-t1-t2});
        M = max(M, i+t1+t2+t3);
    }
    cnt += M;

    cout << cnt << '\n';

    return 0;
}