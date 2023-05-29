#include <iostream>
using namespace std;

int main() {
    int S, K;
    long long ans=1;
    cin >> S >> K;

    while (S>0) {
        ans *= S/K;
        S -= S/K;
        K--;
    }
    cout << ans << '\n';
    return 0;
}