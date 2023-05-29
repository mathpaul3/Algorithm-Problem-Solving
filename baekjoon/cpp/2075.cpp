#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, NN;
    cin >> N;
    NN = N*N;
    while (NN--) {
        int tmp;
        cin >> tmp;
        pq.push(-tmp);
        if (pq.size()>N) {
            pq.pop();
        }
    }
    cout << -pq.top() << '\n';

    return 0;
}