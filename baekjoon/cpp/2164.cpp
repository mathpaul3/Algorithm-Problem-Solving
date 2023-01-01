#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int N;
    cin >> N;
    for (int i=1; i<=N; i++) {
        q.push(i);
    }

    while (true) {
        if (q.size() == 1)
            break;
        q.pop();

        if (q.size() == 1)
            break;
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << '\n';

    return 0;
}