#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

priority_queue<tuple<int,int,int> > edge;

int N, s_paddy, W, Pij, i, j, tot_price=0;
int price_min=100100, paddy[300]={0,}, parent[300]={0,};

int find_parent(int node) {
    if (node==parent[node]) return node;
    else return parent[node] = find_parent(parent[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> paddy[i];
        parent[i] = i;
        if (paddy[i]<price_min) {
            price_min = paddy[i];
            s_paddy = i;
        }
    }
    for (i=0; i<N; i++) {
        if (i!=s_paddy) edge.push(make_tuple(-paddy[i], i, s_paddy));
        else tot_price += paddy[i];
    }
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            cin >> Pij;
            if (i<j) edge.push(make_tuple(-Pij, i, j));
        }
    }
    while (!edge.empty()) {
        tie(Pij, i, j) = edge.top();
        Pij = -Pij;
        edge.pop();
        i = find_parent(i); j = find_parent(j);
        if (i==j) continue;
        if (j<i) { i^=j; j^=i; i^=j; }
        parent[j] = i;
        tot_price += Pij;
    }
    cout << tot_price << '\n';
    return 0;
}