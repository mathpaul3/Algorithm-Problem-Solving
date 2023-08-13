#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    int N, Ai, maximum=0, diff_min, criteria;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> Ai;
        pq.push(-Ai);
        if (maximum < Ai) maximum = Ai;
    }
    criteria = maximum;
    diff_min = maximum - (-pq.top());
    while (true) {
        int top = -pq.top(); pq.pop();
        if (top >= criteria) break;
        int minimum = (top*2<-pq.top() ? top*2 : -pq.top());
        maximum = (top*2>maximum ? top*2 : maximum);
        if (diff_min >= maximum-minimum) {
            diff_min = maximum - minimum;
            pq.push(-top*2);
        }
    }
    cout << diff_min << '\n';
    return 0;
}