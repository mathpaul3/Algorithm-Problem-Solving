#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N<3) cout << 0 << '\n';
    else cout << N*(N-1)*(N-2)*(N-3)/(4*3*2*1) << '\n';
    return 0;
}