#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, num, prv, singer;
int inbound[1001]={0,};
vector<int> adj[1001], answer;
queue<int> zeros;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (M--) {
        cin >> num;
        prv = 0;
        while (num--) {
            cin >> singer;
            if (prv) { adj[prv].push_back(singer); inbound[singer]++; }
            prv = singer;
        }
    }
    
    for (int i=1; i<=N; i++) {
        if (!inbound[i]) zeros.push(i);
    }

    while (!zeros.empty()) {
        int front = zeros.front(), sz=adj[front].size();
        answer.push_back(front); zeros.pop();
        for (int i=0; i<sz; i++) {
            if (!(--inbound[adj[front][i]])) {
                zeros.push(adj[front][i]);
            }
        }
    }

    for (int i=1; i<=N; i++) {
        if (inbound[i]) { cout << 0 << '\n'; return 0; }
    }

    int sz = answer.size();
    for (int i=0; i<sz; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}