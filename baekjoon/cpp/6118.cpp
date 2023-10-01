#include <iostream>
#include <set>
#include <queue>
using namespace std;

int N, M, A_i, B_i, dist=-1, barn, cnt;
bool visited[20001]={0,};
set<int> adj[20001];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (M--) {
        cin >> A_i >> B_i;
        adj[A_i].insert(B_i);
        adj[B_i].insert(A_i);
    }
    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        dist++;
        barn = N+1;
        cnt = q.size();
        for (int i=0; i<cnt; i++) {
            int cur = q.front(); q.pop();
            if (cur<barn) barn = cur;
            for (auto it=adj[cur].begin(); it!=adj[cur].end(); it++) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
    }
    cout << barn << ' ' << dist << ' ' << cnt << '\n';
    return 0;
}