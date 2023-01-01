#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
priority_queue<int> pq;
int T, N, M, n, i, ans, tmppq;
pair<int,int> m, tmpq;

int main() {
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        for (i=0; i<N; i++)
        {
            cin >> n;
            q.push({n, i});
            pq.push(n);
            if (i == M)
                m = {n, i};
        }

        ans = 1;
        tmpq = q.front();
        tmppq = pq.top();
        
        while (tmpq.first != tmppq || tmpq.second != m.second)
        {
            if (tmpq.first == tmppq)
            {
                ans++;
                pq.pop();
                tmppq = pq.top();
            }
            q.push(tmpq);
            q.pop();
            tmpq = q.front();
        }

        cout << ans << endl;

        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();
    }
    return 0;
}