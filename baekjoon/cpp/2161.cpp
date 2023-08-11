#include <iostream>
#include <queue>
using namespace std;

int N;
bool b = false;
queue<short> q;

int main() {
    cin >> N;
    for (short i=1; i<=N; i++)
        q.push(i);
    while (!q.empty()) {
        if (b) q.push(q.front());
        else cout << q.front() << ' ';
        q.pop();
        b = !b;
    }
    return 0;
}