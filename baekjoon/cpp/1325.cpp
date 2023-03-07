#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];
int computer[10001]={0,};
int N, M, A, B, maximum=0;

int BFS(int start) {
    queue<int> q; q.push(start);
    bool visit[10001] = {0,}; visit[start] = true;
    int cnt = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int sz = adj[cur].size();
        for (int i=0; i<sz; i++) {
            int next = adj[cur][i];
            if (!visit[next]) {
                cnt++; visit[next] = true;
                q.push(next);
            }
        }
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        adj[B].push_back(A);
    }
    for (int i=1; i<=N; i++) {
        computer[i] = BFS(i);
        if (computer[i]>maximum) maximum = computer[i];
    }
    for (int i=1; i<=N; i++)
        if (computer[i] == maximum)
            cout << i << ' ';
    return 0;
}