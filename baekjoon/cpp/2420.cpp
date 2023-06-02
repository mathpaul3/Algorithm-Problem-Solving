#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    if (N>M) { N ^= M; M ^= N; N ^= M; }
    cout << M-N << '\n';
    return 0;
}