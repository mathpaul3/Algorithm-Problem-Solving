#include <iostream>
using namespace std;

int main() {
    long long N, A, Pa, B, Pb, a, maxPower=0, maxX=0, maxY=0;
    cin >> N >> A >> Pa >> B >> Pb;

    a = N/Pa;
    for (; a>=0; a--) {
        long long x = a, y = (N-(a*Pa))/Pb, power = A*x+B*y;
        if (power>maxPower) {
            maxX = x; maxY = y; maxPower = power;
        }
    }
    cout << maxX << ' ' << maxY << '\n';
    return 0;
}