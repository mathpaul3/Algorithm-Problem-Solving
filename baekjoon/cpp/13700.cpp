#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<int> q;
    int N, S, D, F, B, K, I, cnt=0;
    bool police[100001]={0,}, visited[100001]={0,};
    cin >> N >> S >> D >> F >> B >> K;
    for (int i=0; i<K; i++) {
        cin >> I;
        police[I] = true;
    }
    q.push(S);
    visited[S] = true;
    while (!q.empty()) {
        bool flag = false;
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            int f = q.front();
            if (f == D) { flag = true; break; }
            if (f-B>0 && !visited[f-B] && !police[f-B]) {
                q.push(f-B);
                visited[f-B] = true;
            }
            if (f+F<=N && !visited[f+F] && !police[f+F]) {
                q.push(f+F);
                visited[f+F] = true;
            }
            q.pop();
        }
        if (flag) break;
        cnt++;
    }
    if (q.empty()) cout << "BUG FOUND\n";
    else cout << cnt << '\n';
    
    return 0;
}