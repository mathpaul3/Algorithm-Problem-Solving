#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, A, B, incoming_edge[32001]={0,};
    vector<int> adj[32001];
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        incoming_edge[B]++;
    }
    queue<int> order;
    for (int i=1; i<=N; i++)
        if (!incoming_edge[i]) order.push(i);
    priority_queue<pair<int,int> > line;
    int cur=N;
    while (!order.empty()) {
        int front = order.front(); order.pop();
        int sz = adj[front].size();
        line.push(make_pair(cur--, front));
        for (int i=0; i<sz; i++) {
            incoming_edge[adj[front][i]]--;
            if (!incoming_edge[adj[front][i]]) order.push(adj[front][i]);
        }
    }
    while (!line.empty()) {
        cout << line.top().second << ' ';
        line.pop();
    }
    return 0;
}