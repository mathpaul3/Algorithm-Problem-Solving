#include <iostream>
using namespace std;

int N, L, parent[300001]={0,};
bool visited[300001]={0,};

int find_parent(int n) {
    if (parent[n]==n) return n;
    else return parent[n] = find_parent(parent[n]);
}

void merge(int i, int j) {
    i = find_parent(i);
    j = find_parent(j);
    parent[i] = j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    for (int i=1; i<=L; i++) parent[i] = i;
    for (int i=1; i<=N; i++) {
        bool flag = true;
        int A, B;
        cin >> A >> B;
        if (!visited[A]) {
            visited[A] = true;
            merge(A, B);
        } else if (!visited[B]) {
            visited[B] = true;
            merge(B, A);
        } else if (!visited[find_parent(A)]) {
            visited[find_parent(A)] = true;
            merge(A, B);
        } else if (!visited[find_parent(B)]) {
            visited[find_parent(B)] = true;
            merge(B, A);
        } else flag = false;
        cout << (flag ? "LADICA\n" : "SMECE\n");
    }
    return 0; 
}