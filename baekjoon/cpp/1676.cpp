#include <iostream>
using namespace std;

int main() {
    int N, twos=0, fives=0;
    cin >> N;
    for (int i=2; i<=N; i++) {
        int tmp=i;
        if (!(i%2)) {
            while (!(tmp%2))
            { twos++; tmp /= 2; }
        }
        tmp = i;
        if (!(i%5)) {
            while (!(tmp%5))
            { fives++; tmp /= 5; }
        }
    }
    cout << (twos>fives ? fives : twos) << '\n';
    return 0;
}