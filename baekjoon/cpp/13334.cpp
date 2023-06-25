#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, hi, oi, d;
pair<int,int> people[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> hi >> oi;
        if (hi>oi) { hi ^= oi; oi ^= hi; hi ^= oi; }
        people[i].first = oi;
        people[i].second = hi;
    }
    cin >> d;
    sort(people, people+n);

    priority_queue<int> pq;
    int Ls, Le, M=0;
    for (int i=0; i<n; i++) {
        Le = people[i].first; Ls = Le-d;
        pq.push(-people[i].second);
        while (!pq.empty() && -pq.top()<Ls) pq.pop();
        if (M<pq.size()) M = pq.size();
    }
    cout << M << '\n';

    return 0;
}