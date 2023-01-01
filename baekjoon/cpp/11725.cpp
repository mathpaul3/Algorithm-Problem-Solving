#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int parent[100001];
bool visited[100001];

void find_child(int node) {
    int sz = tree[node].size();

    for (int i=0; i<sz; i++) {
        int child = tree[node][i];
        if (visited[child]) continue;
        visited[child] = true;
        parent[child] = node;
        find_child(tree[node][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, u, v;
    cin >> N;

    for (int i=1; i<N; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[1] = true;
    find_child(1);

    for (int i=2; i<=N; i++)
        cout << parent[i] << '\n';

    return 0;
}