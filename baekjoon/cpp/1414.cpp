#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

priority_queue<tuple<int,int,int> > pq;
int N, i, j, group[50], donate=0;
char len;

int master(int computer) {
    if (group[computer]==computer) return computer;
    else return group[computer] = master(group[computer]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (i=0; i<N; i++) {
        group[i] = i;
        for (j=0; j<N; j++) {
            cin >> len;
            if (len=='0') continue;
            pq.push(make_tuple(len>'Z' ? -(len-'a'+1): -(len-'A'+27), i, j));
        }
    }
    while (!pq.empty()) {
        tie(len, i, j) = pq.top(); pq.pop();
        len = -len;
        i = master(i); j = master(j);
        if (i==j) {
            donate += len;
            continue;
        }
        if (i>j) { i^=j; j^=i; i^=j; }
        group[j] = i;
    }
    for (i=0; i<N; i++) {
        group[i] = master(group[i]);
        if (group[i]!=0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << donate << '\n';
    return 0;
}