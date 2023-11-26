#include <iostream>
#include <stack>
using namespace std;

int N, C_i, D_i;
stack<int> unwashed, undried, done;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=N; i>=1; i--) unwashed.push(i);
    while (cin >> C_i >> D_i) {
        if (C_i==1) {
            for (int i=0; i<D_i; i++) {
                undried.push(unwashed.top());
                unwashed.pop();
            }
        } else {
            for (int i=0; i<D_i; i++) {
                done.push(undried.top());
                undried.pop();
            }
        }
    }
    while (!done.empty()) {
        cout << done.top() << '\n';
        done.pop();
    }
    return 0;
}