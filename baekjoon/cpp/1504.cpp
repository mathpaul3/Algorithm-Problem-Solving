#include <iostream>
#include <queue>
#include <vector>
#define SIZE 801
#define INF 2100000000
using namespace std;

int d[SIZE];

void init(int size) {
    for (int i=1; i<=size; i++)
        d[i] = INF;
}

void dijkstra(int start, vector<pair<int,int> > *adj) {
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int new_d = adj[cur][i].second + d[cur];
            if (new_d < d[next]) {
                d[next] = new_d;
                pq.push(make_pair(-d[next], next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E, a, b, c, v1, v2;
    vector<pair<int,int> > adj[SIZE];
    int special_adj[4][4];
    cin >> N >> E;
    while (E--) {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;
    init(N);
    dijkstra(1, adj);
    special_adj[0][1] = d[v1];
    special_adj[0][2] = d[v2];

    init(N);
    dijkstra(v1, adj);
    special_adj[1][0] = d[1];
    special_adj[1][2] = d[v2];
    special_adj[1][3] = d[N];

    init(N);
    dijkstra(v2, adj);
    special_adj[2][0] = d[1];
    special_adj[2][1] = d[v1];
    special_adj[2][3] = d[N];

    int min = INF;
    int route = INF;
    if (special_adj[0][1] != INF && special_adj[1][2] != INF && special_adj[2][3] != INF)
        route = special_adj[0][1] + special_adj[1][2] + special_adj[2][3];
    min = (min > route ? route : min);
    if (special_adj[0][2] != INF && special_adj[2][1] != INF && special_adj[1][3] != INF)
        route = special_adj[0][2] + special_adj[2][1] + special_adj[1][3];
    min = (min > route ? route : min);

    cout << (min == INF ? -1 : min) << '\n';
    
    return 0;
}