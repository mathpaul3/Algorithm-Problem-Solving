#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<pair<int,int> > pq;
    int N, age;
    cin >> N;
    string names[N];
    for (int i=0; i<N; i++) {
        cin >> age >> names[i];
        pq.push(make_pair(-age, -i));
    }

    while (!pq.empty()) {
        cout << -pq.top().first << " " << names[-pq.top().second] << '\n';
        pq.pop();
    }

    return 0;
}