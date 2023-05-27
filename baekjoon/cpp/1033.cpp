#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10];
int N, ingredient[10]={0,};

void multiply(int ingred, int mul) {
    bool visit[10]={0,};
    queue<int> q;
    q.push(ingred);
    ingredient[ingred] *= mul;
    visit[ingred] = true;
    while (!q.empty()) {
        int front = q.front(); q.pop();
        for (int num: adj[front]) {
            if (!visit[num]) {
                ingredient[num] *= mul;
                visit[num] = true;
                q.push(num);
            }
        }
    }
    return;
}

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) ingredient[i] = 1;
    for (int i=0; i<N-1; i++) {
        int a, b, p, q, div;
        cin >> a >> b >> p >> q;
        div = gcd(p*ingredient[b], q*ingredient[a]);
        p = p*ingredient[b]/div;
        q = q*ingredient[a]/div;
        multiply(a, p);
        multiply(b, q);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<N; i++)
        cout << ingredient[i] << ' ';
    return 0;
}