#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

int dist[20001], V, E, K;
vector<pair<int,int> > graph[20001];


void dijkstra(int start) {
    for (int i=1; i<=V; i++)
        dist[i] = INF;

    priority_queue<pair<int,int> > pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int cur = pq.top().second;
        int size = graph[cur].size();
        for (int i=0; i<size; i++) {
            int n = graph[cur][i].first;
            int w = graph[cur][i].second;
            if (dist[n] > dist[cur] + w) {
                dist[n] = dist[cur] + w;
                pq.push(make_pair(-dist[n], n));
            }
        }
        pq.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    cin >> K;

    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    dijkstra(K);

    for (int i=1; i<=V; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}