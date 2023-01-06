#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
queue<int> q;

int main() {
    int N, K, cur, time=0, route=0;
    cin >> N >> K;

    q.push(N);
    while (true) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            cur = q.front();
            if (cur == K) route++;
            
            if (cur > 0 && !visited[cur-1]) {
                q.push(cur-1);
            }
            if (cur < 100001 && !visited[cur+1]) {
                q.push(cur+1);
            }
            if (cur*2 < 100001 && !visited[cur*2]) {
                q.push(cur*2);
            }
            visited[cur] = true;
            q.pop();
        }
        if (route)
            break;
        time++;
    }

    cout << time << '\n' << route << '\n';

    return 0;
}