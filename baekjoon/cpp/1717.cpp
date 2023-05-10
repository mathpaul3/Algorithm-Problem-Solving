#include <iostream>
#define JOIN 0
#define CHECK 1
using namespace std;

int group[1000001]={0,};

int find_parent(int node) {
    if (group[node] == node) return node;
    return group[node] = find_parent(group[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        group[i] = i;

    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == JOIN) {
            a = find_parent(a);
            b = find_parent(b);
            if (a>b) {
                a ^= b; b ^= a; a ^= b;
            }
            group[b] = a;
        } else if (op == CHECK) {
            a = find_parent(a);
            b = find_parent(b);
            cout << (a==b ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}