#include <iostream>
using namespace std;

int main() {
    int A, B, N;
    cin >> A >> B >> N;
    A %= B;
    while (N--) {
        A *= 10;
        if (!N) cout << A/B << '\n';
        A -= A/B*B;
    }
    return 0;
}