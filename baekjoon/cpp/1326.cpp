#include <iostream>
#include <queue>
using namespace std;

int N, a, b, bridge[10001]={0,};

int jump(int start, int goal) {
    queue<int> q;
    bool visit[10001]={0,};
    int cnt=0;
    q.push(start);
    visit[start]=true;
    while (!q.empty()) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            int cur = q.front(); q.pop();
            int m = -((cur-1)/bridge[cur]);
            int M = (N-cur)/bridge[cur];
            for (int i=m; i<=M; i++) {
                int curi = cur+i*bridge[cur];
                if (curi == b) return ++cnt;
                if (!visit[curi]) {q.push(curi); visit[curi]=true;}
            }
        }
        cnt++;
    }
    return -1;
}


int main() {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> bridge[i];
    cin >> a >> b;
    cout << jump(a, b) << '\n';
    return 0;
}