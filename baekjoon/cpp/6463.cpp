#include <iostream>
using namespace std;

int main() {
    int N, fact;
    while (cin >> N) {
        fact = 1;
        for (int i=1; i<=N; i++) {
            fact *= i;
            while (!(fact%10)) fact /= 10;
            fact %= 100000;
        }
        cout.width(5);
        cout << N;
        cout << " -> " << fact%10 << '\n';
    }
    return 0;
}