#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    deque<int> dq;
    int N, M, num, cnt=0;
    cin >> N >> M;
    for (int i=1; i<=N; i++) dq.push_back(i);
    while (M--) {
        cin >> num;
        int idx=0;
        for (auto it=dq.begin(); it!=dq.end(); it++) {
            if (*it==num) break;
            else idx++;
        }
        if (idx<=dq.size()-1-idx) {
            cnt += idx;
            for (int i=0; i<idx; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        } else {
            cnt += dq.size()-idx;
            for (int i=0; i<dq.size()-1-idx; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.pop_back();
        }
    }
    cout << cnt << '\n';
    return 0;
}