#include <iostream>
using namespace std;

int main() {
    int L, A, B, C, D, ko, math;
    cin >> L >> A >> B >> C >> D;
    ko = A/C+(A%C ? 1 : 0);
    math = B/D+(B%D ? 1 : 0);
    cout << L - (ko < math ? math : ko) << '\n';
    return 0;
}