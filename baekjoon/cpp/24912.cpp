#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, cur, prev, pprev, cards[1000000]={0,};
    bool impossible=false;
    cin >> N;
    for (int i=0; i<=N; i++) {
        if (i<N) {
            cin >> cards[i];
            cur = cards[i];
        }
        else cur = 0;
        if (1<i) {
            prev = cards[i-1];
            pprev = cards[i-2];
            if (cur && cur == prev) {impossible = true; continue;}
            if (!prev) {
                if (!cur || pprev == cur) {
                    for (int j=1; j<4; j++)
                        if (j != pprev) {cards[i-1]=j; break;}
                } else cards[i-1] = 6-(pprev+cur);
            }
        } else if (0<i) {
            prev = cards[i-1];
            if (cur && cur == prev) {impossible = true; continue;}
            if (!prev)
                for (int j=1; j<4; j++)
                    if (j != cur) {cards[i-1]=j; break;}
        }
    }
    if (impossible) cout << -1 << '\n';
    else
        for (int i=0; i<N; i++)
            cout << cards[i] << ' ';
    return 0;
}