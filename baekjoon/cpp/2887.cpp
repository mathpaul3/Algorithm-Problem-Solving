#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int,int> > X, Y, Z;
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > A;
int N;
pair<int,int> X_prev, Y_prev, Z_prev, X_cur, Y_cur, Z_cur;
int cycle_table[100000];


int get_parent(int planet) {
    if (cycle_table[planet] == planet)
        return planet;
    return get_parent(cycle_table[planet]);
}

bool is_different_parent(int u, int v) {
    u = get_parent(u);
    v = get_parent(v);

    return (u != v);
}

void union_parent(int u, int v) {
    u = get_parent(u);
    v = get_parent(v);
    if (u < v) cycle_table[v] = u;
    else cycle_table[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        X.push(make_pair(x, i));
        Y.push(make_pair(y, i));
        Z.push(make_pair(z, i));
    }

    X_prev = X.top(); X.pop();
    Y_prev = Y.top(); Y.pop();
    Z_prev = Z.top(); Z.pop();
    while (!X.empty()) {
        X_cur = X.top(); X.pop();
        A.push(make_tuple(X_prev.first-X_cur.first, X_prev.second, X_cur.second));
        Y_cur = Y.top(); Y.pop();
        A.push(make_tuple(Y_prev.first-Y_cur.first, Y_prev.second, Y_cur.second));
        Z_cur = Z.top(); Z.pop();
        A.push(make_tuple(Z_prev.first-Z_cur.first, Z_prev.second, Z_cur.second));
        X_prev = X_cur; Y_prev = Y_cur; Z_prev = Z_cur;
    }

    for (int i=1; i<=N; i++)
        cycle_table[i] = i;

    int sum = 0;
    while (!A.empty()) {
        tuple<int,int,int> cur = A.top();
        if (is_different_parent(get<1>(cur), get<2>(cur))) {
            sum += get<0>(cur);
            union_parent(get<1>(cur), get<2>(cur));
        }
        A.pop();
    }

    cout << sum << '\n';

    return 0;
}


// Kruskal's MST
// X 기준 pq 삽입 16 * 10 0000
// Y 기준 pq 삽입 
// Z 기준 pq 삽입
// 48 * 10 0000

// 셋 다 돌며 axis[i+1] - axis[i]하여 pq에 push
// 18 * 30 0000

// 1020 0000

// pq에서 빼내면서 union
// 모든 행성이 union 되었으면 종료
// 16 * 10 0000
