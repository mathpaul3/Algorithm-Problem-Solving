#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int,int> > pq;
int R, C, cnt=0, rankk[10]={0,};
char chr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> chr;
            if (chr!='.' && chr!='S' && chr!='F') {
                cnt++;
                if (cnt == 3) {
                    pq.push(make_pair(j, chr-'0'));
                    cnt = 0;
                }
            }
        }
    }

    int prv=pq.top().first, idx=pq.top().second, rnk=1;
    pq.pop(); rankk[idx] = rnk;
    while (!pq.empty()) {
        int cur=pq.top().first;
        idx=pq.top().second; pq.pop();
        if (prv == cur) rankk[idx] = rnk;
        else rankk[idx] = ++rnk;
        prv = cur;
    }
    for (int i=1; i<10; i++) cout << rankk[i] << '\n';

    return 0;
}