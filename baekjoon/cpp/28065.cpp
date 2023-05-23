#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, prev=1, mul=1;
    cin >> N;
    cout << prev << ' ';
    while (--N) {
        prev = prev + mul*N;
        mul *= -1;
        cout << prev << ' ';
    }

    return 0;
}