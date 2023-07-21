#include <iostream>
using namespace std;

int N, M, cities[201]={0,}, connection, plan_cur, plan_prev;
bool possible = true;

int parent(int city) {
    if (city==cities[city]) return city;
    return cities[city] = parent(cities[city]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++) cities[i] = i;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> connection;
            if (connection) {
                int i_parent = parent(i);
                int j_parent = parent(j);
                if (i_parent>j_parent) { i_parent ^= j_parent; j_parent ^= i_parent; i_parent ^= j_parent; }
                cities[j_parent] = i_parent;
            }
        }
    }
    cin >> plan_prev;
    for (int i=1; i<M; i++) {
        cin >> plan_cur;
        if (possible && parent(plan_cur)==parent(plan_prev)) {
            plan_prev = plan_cur;
        } else possible = false;
    }
    cout << (possible ? "YES" : "NO") << '\n';
    return 0;
}