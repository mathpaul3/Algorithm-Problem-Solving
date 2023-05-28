#include <iostream>
using namespace std;

int N, M, K, T, magic=0, lcur=0, rcur=0, l=0, r=0, diff_M=0;
pair<int,int> mofumofu[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> T;
    
    for (int i=0; i<N; i++)
        cin >> mofumofu[i].first >> mofumofu[i].second;
    
    while (r<M) {
        if (magic<K) {
            if (rcur!=0 || mofumofu[rcur].first!=0) {
                r += T;
                magic++;
            }
            if (rcur<N && r>=mofumofu[rcur].first) {
                r = mofumofu[rcur].second;
                rcur++;
            }
            if (r>M) r = M;
        } else {
            magic--;
            if (lcur<N) {
                if (mofumofu[lcur].first==l) l = mofumofu[lcur++].second;
                if (lcur<N) l += ((mofumofu[lcur].first-l)%T ? (mofumofu[lcur].first-l)%T : T);
                else l += T;
            } else l += T;
            if (l>M) l = M;
        }
        if (r-l>diff_M) diff_M = r-l;
    }
    cout << diff_M << '\n';
    return 0;
}