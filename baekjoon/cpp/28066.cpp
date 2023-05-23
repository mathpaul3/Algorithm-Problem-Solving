#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, K;
    queue<int> q;
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        q.push(i);
    }
    
    while (true) {
        q.push(q.front());
        q.pop();
        for (int i=1; i<K; i++) {
            if (q.size()==1) {
                cout << q.front() << '\n';
                return 0;
            }
            q.pop();
        }
    }
}