#include <iostream>
#include <queue>
using namespace std;

int N, C, E_i, B1_i, B2_i, d=0, dist[100001]={0,};
pair<int,int> pipe[100001];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;
    while (C--) {
        cin >> E_i >> B1_i >> B2_i;
        pipe[E_i].first = B1_i;
        pipe[E_i].second = B2_i;
    }
    q.push(1);
    while (!q.empty()) {
        d++;
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            int p = q.front(); q.pop();
            dist[p] = d;
            if (pipe[p].first) q.push(pipe[p].first);
            if (pipe[p].second) q.push(pipe[p].second);
        }
    }
    for (int i=1; i<=N; i++) cout << dist[i] << '\n';
    return 0;
}