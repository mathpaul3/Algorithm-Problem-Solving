#include <iostream>
#include <queue>
#include <vector>
#define SIZE 1010
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
            int new_dist = adj[cur][i].second + d[cur];
            if (new_dist < d[next]) {
                d[next] = new_dist;
                pq.push(make_pair(-d[i], next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, X, A, B, Ti;
    vector<pair<int,int> > adj_in[SIZE];
    vector<pair<int,int> > adj_out[SIZE];
    cin >> N >> M >> X;

    int *shuttle = new int[N+1];
    for (int i=0; i<=N; i++)
        shuttle[i] = 0;

    while(M--) {
        cin >> A >> B >> Ti;
        adj_in[A].push_back(make_pair(B, Ti));
        adj_out[B].push_back(make_pair(A, Ti));
    }

    init(N);
    dijkstra(X, adj_in);
    for (int i=1; i<=N; i++)
        shuttle[i] += d[i];

    init(N);
    dijkstra(X, adj_out);
    int max=0;
    for (int i=1; i<=N; i++) {
        shuttle[i] += d[i];
        max = (shuttle[i] > max ? shuttle[i] : max);
    }

    cout << max << '\n';

    return 0;
}