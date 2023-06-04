#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, P[50000]={0,};
    priority_queue<pair<int,int> > mine;
    priority_queue<int> ans;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> P[i];
        mine.push(make_pair(P[i], i));
    }

    while (!mine.empty()) {
        int pi=mine.top().first, idx=mine.top().second;
        int left=idx, right=idx;
        mine.pop();
        if (!P[idx]) continue;
        
        while (left>=0 && P[left]>P[left-1]) {
            P[left] = 0;
            left--;
        }
        if (left>=0) P[left] = 0;
        P[idx] = pi;
        while (right<N && P[right]>P[right+1]) {
            P[right] = 0;
            right++;
        }
        if (right<N) P[right] = 0;
        ans.push(-idx);
    }
    while (!ans.empty()) {
        cout << -ans.top()+1 << '\n';
        ans.pop();
    }
    return 0;
}