#include <iostream>
using namespace std;

int main() {
    long long N, ans=1;
    cin >> N;
    N++;
    while ((N = N-2) > 0)
        ans = (ans * N) % (long long)(1e9+7);
    cout << ans << '\n';
    return 0;
}