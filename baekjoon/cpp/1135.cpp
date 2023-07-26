#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, tmp;
vector<pair<int,int> > adj[50];

int spread(int employee) {
    int maximum=0;
    int sz = adj[employee].size();
    if (!sz) return 0;
    for (int i=0; i<sz; i++) {
        adj[employee][i].first = spread(adj[employee][i].second);
    }
    sort(adj[employee].begin(), adj[employee].end());
    for (int i=0; i<sz; i++) {
        if (maximum < adj[employee][i].first+(sz-i))
            maximum = adj[employee][i].first+(sz-i);
    }
    return maximum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> tmp;
    for (int i=1; i<N; i++) {
        cin >> tmp;
        adj[tmp].push_back(make_pair(0, i));
    }
    cout << spread(0) << '\n';
    return 0;
}