#include <iostream>
using namespace std;

int n, m, A, B, group[500000]={0,};
bool found=false;

int find_parent(int dot) {
    if (group[dot] == dot) return dot;
    return group[dot] = find_parent(group[dot]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++) group[i] = i;
    for (int i=1; i<=m; i++) {
        cin >> A >> B;
        if (found) continue;
        A = find_parent(A); B = find_parent(B);
        if (A == B) {
            found = true;
            cout << i << '\n';
        } else {
            if (A<B) group[B] = A;
            else group[A] = B;
        }
    }
    if (!found) cout << 0 << '\n';
    return 0;
}