#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    short N, K;
    queue<short> q;
    cin >> N >> K;
    for (short i=1; i<=N; i++) q.push(i);
    cout << '<';
    while (!q.empty()) {
        for (short i=1; i<K; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << (q.size()==1 ? ">\n" : ", ");
        q.pop();
    }
    return 0;
}