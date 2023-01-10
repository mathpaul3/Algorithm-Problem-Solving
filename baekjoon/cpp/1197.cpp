#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int V, E;
int parent[10001];
vector<tuple<int,int,int> > e;

bool cmp(tuple<int,int,int> u, tuple<int,int,int> v) {
	return get<2>(u) < get<2>(v);
}

int find_parent(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find_parent(parent[node]);
}

bool union_parent(int u, int v) {
	u=find_parent(u), v=find_parent(v);
	if (u == v) return false;
	if (u < v) parent[v] = u;
	else parent[u] = v;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	
	int A, B, C;
	for (int i=0; i<E; i++) {
		cin >> A >> B >> C;
		e.push_back(make_tuple(A, B, C));
	}
	sort(e.begin(), e.end(), cmp);

	for (int i=1; i<=V; i++)
		parent[i] = i;
	
	int sum=0;
	for (int i=0; i<E; i++)
		if (union_parent(get<0>(e[i]), get<1>(e[i])))
			sum += get<2>(e[i]);

	cout << sum << '\n';
	
	return 0;
}
