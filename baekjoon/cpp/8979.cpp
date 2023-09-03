#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    tuple<int,int,int,int> medal[1000];
    int N, K, prvg, prvs, prvb, curg, curs, curb, country, rank=1;
    cin >> N >> K;
    for (int i=0; i<N; i++)
        cin >> get<3>(medal[i]) >> get<0>(medal[i]) >> get<1>(medal[i]) >> get<2>(medal[i]);
    sort(medal, medal+N);
    if (get<3>(medal[N-1])==K) { cout << 1 << '\n'; return 0; }
    for (int i=N-2; i>=0; i--) {
        tie(prvg, prvs, prvb, country) = medal[i+1];
        tie(curg, curs, curb, country) = medal[i];
        if (curg!=prvg || curs!=prvs || curb!=prvb) rank = N-i;
        if (country==K) { cout << rank << '\n'; return 0; }
    }
    return 0;
}