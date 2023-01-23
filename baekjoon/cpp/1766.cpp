#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int prior[32001]={0,}, N, M, A, B;
vector<int> adj[32001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        adj[A].push_back(B);
        prior[B]++;
    }

    priority_queue<int> order;
    for (int i=1; i<=N; i++)
        if (!prior[i]) order.push(-i);
    
    while (!order.empty()) {
        int top = -order.top(); order.pop();
        cout << top << ' ';
        int sz = adj[top].size();
        for (int i=0; i<sz; i++) {
            if (!(--prior[adj[top][i]]))
                order.push(-adj[top][i]);
        }
    }

    return 0;
}