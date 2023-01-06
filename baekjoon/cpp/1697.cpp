#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
queue<int> q;

int main() {
    int N, K, cur, time=0;
    cin >> N >> K;

    visited[N] = true;
    q.push(N);
    while (true) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            cur = q.front();
            if (cur == K) break;
            
            if (cur > 0 && !visited[cur-1]) {
                visited[cur-1] = true;
                q.push(cur-1);
            }
            if (cur < 100001 && !visited[cur+1]) {
                visited[cur+1] = true;
                q.push(cur+1);
            }
            if (cur*2 < 100001 && !visited[cur*2]) {
                visited[cur*2] = true;
                q.push(cur*2);
            }
            q.pop();
        }
        if (cur == K)
            break;
        time++;
    }

    cout << time << '\n';

    return 0;
}