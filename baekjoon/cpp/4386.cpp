#include <iostream>
#include <queue>
#include <tuple>
#include <math.h>
using namespace std;

int i, j, n, parent[100];
double dist, answer=0;
pair<double,double> point[100];
priority_queue<tuple<double,int,int> > pq;

int find_parent(int node) {
    if (node == parent[node]) return node;
    else return parent[node] = find_parent(parent[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> point[i].first >> point[i].second;
        parent[i] = i;
    }

    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            pq.push(make_tuple(-sqrt((point[i].first-point[j].first)*(point[i].first-point[j].first)+(point[i].second-point[j].second)*(point[i].second-point[j].second)), i, j));
        }
    }
    while (!pq.empty()) {
        tie(dist, i, j) = pq.top(); pq.pop();
        dist = -dist;
        i = find_parent(i); j = find_parent(j);
        if (i==j) continue;
        if (i>j) { j^=i; i^=j; j^=i; }
        parent[i] = j;
        answer += dist;
    }
    cout << fixed;
    cout.precision(2);
    cout << answer << '\n';
    return 0;
}