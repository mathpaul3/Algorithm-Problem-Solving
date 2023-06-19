#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, dasom, tmp, sum=0;
    priority_queue<int> pq;
    cin >> N;
    cin >> dasom;
    for (int i=1; i<N; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    if (pq.empty()) {
        cout << sum << '\n';
        return 0;
    }
    while (pq.top()>=dasom) {
        tmp = pq.top(); pq.pop();
        dasom++;
        sum++;
        pq.push(--tmp);
    }
    cout << sum << '\n';

    return 0;
}