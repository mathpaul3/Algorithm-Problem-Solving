#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M, K, T, u, v, ord=1;
bool is_infected[300001];
int survive[300001], parent[300001];
vector<int> adj[300001];

int min(int x, int y) {
    return x<y ? x : y;
}

tuple<int,int,int> cutting_edge(int v, bool is_root) {
    parent[v] = ord++;
    int degree = 0;
    int ret = parent[v];
    bool is_cutting = false;
    
    int child_sum = 0;
    int other_child_sum = 0;
    int infected_sum = 0;
    int other_infected_sum = 0;
    int survive_sum = 0;

    for (auto it=adj[v].begin(); it!=adj[v].end(); it++) {
        int u = *it;
        if (parent[u]) {
            ret = min(ret, parent[u]);
            continue;
        }
        degree++;
        int result, chi, inf;
        tie(result, chi, inf) = cutting_edge(u, false);
        if (result >= parent[v]) {
            child_sum += chi;
            infected_sum += inf;
            if (inf<T) survive_sum += chi-inf;
        } else {
            other_child_sum += chi;
            other_infected_sum += inf;
        }
        if (!is_root && result >= parent[v])
            is_cutting = true;
        ret = min(ret, result);
    }
    if (is_root && degree>1) is_cutting = true;

    if (is_cutting) {
        if (K-infected_sum-is_infected[v]<T)
            survive_sum += (N-child_sum-1) - (K - infected_sum - is_infected[v]);
        survive[v] = survive_sum;
    } else survive[v] = (K-is_infected[v]<T ? (N-1)-(K-is_infected[v]) : 0);
    return make_tuple(ret, child_sum+other_child_sum+1, infected_sum+other_infected_sum+is_infected[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> T;
    while (M--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=0; i<K; i++) {
        cin >> v;
        is_infected[v] = true;
    }
    
    cutting_edge(1, true);
    
    for (int i=1; i<=N; i++) {
        cout << survive[i]+!(is_infected[i]) << ' ';
    }
    return 0;
}


/*
10 10 4 2
1 3
2 3
3 4
6 5
5 4
4 7
7 8
8 9
7 9
10 9
2
4
8
9
*/

/*
10 12 3 2
10 9
8 9
7 9
7 8
7 1
1 2
2 3
2 5
3 5
3 4
4 5
5 6
10
2
5
*/

/*
12 12 2 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 1
2
8
*/

/*
11 14 4 2
9 8
8 2
2 1
2 3
3 1
1 4
3 4
10 3
10 11
11 4
4 6
6 5
5 4
5 7
9
2
4
6
*/

/*
23 32 4 2
16 17
15 16
15 17
13 15
13 14
12 13
12 14
11 12
3 11
3 12
3 4
2 3
2 4
2 10
2 5
2 7
5 7
6 7
1 7
1 6
1 9
1 8
8 9
8 19
8 18
18 19
18 20
20 21
18 21
19 22
22 23
19 23
4
15
7
8
*/