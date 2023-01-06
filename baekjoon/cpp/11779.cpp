#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 2100000000
using namespace std;

vector<pair<int,int> > adj[1001];
int d[1001];
int prv[1001];
int n, m;

void path(int node, int depth) {
	if (prv[node] == node) {
		cout << depth << '\n';
		cout << node << ' ';
		return;
	}
	path(prv[node], depth+1);
	cout << node << ' ';
}

void dijkstra(int start) {
	for (int i=1; i<=n; i++)
		d[i] = INF;
	d[start] = 0;
	prv[start] = start;

	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0, start));

	while(!pq.empty()) {
		int cur = pq.top().second;
		int cur_cost = -pq.top().first;
		pq.pop();
		if (d[cur] < cur_cost)
			continue;

		int sz = adj[cur].size();
		for (int i=0; i<sz; i++) {
			int next = adj[cur][i].first;
			int next_cost = adj[cur][i].second;
			if (d[cur] + next_cost < d[next]) {
				d[next] = d[cur] + next_cost;
				prv[next] = cur;
				pq.push(make_pair(-d[next], next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int dept, ariv, cost;

	cin >> n >> m;

	while (m--) {
		cin >> dept >> ariv >> cost;
		adj[dept].push_back(make_pair(ariv, cost));
	}

	cin >> dept >> ariv;
	dijkstra(dept);

	cout << d[ariv] << '\n';
	path(ariv, 1);

	return 0;
}
