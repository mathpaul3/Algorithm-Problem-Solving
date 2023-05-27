#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

priority_queue<tuple<int,int,int> > pq;
int building[2001]={0,};

int parent(int node) {
    if (node == building[node]) return node;
    else return building[node] = parent(building[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, S;
    cin >> N >> M >> S;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push(make_tuple(-w, u, v));
    }

    for (int i=1; i<=N; i++) {
        int Ai;
        cin >> Ai;
        building[i] = i;
    }
    
    int cnt=1, sum=0;
    while (!pq.empty()) {
        int u, v, w;
        tie(w, u, v) = pq.top();
        w = -w;
        pq.pop();
        u = parent(u);
        v = parent(v);
        if (u==v) continue;
        if (u>v) {
            u ^= v; v ^= u; u ^= v;
        }
        building[v] = u;
        sum += w;
        cnt++;
        if (cnt == N) break;
    }

    cout << sum << '\n';
    return 0;
}