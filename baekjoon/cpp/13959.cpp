#include <iostream>
using namespace std;

int main() {
    int D, R, T, tot_candle;
    int rita_age=4, theo_age=3, rita_candle=0, theo_candle=0;
    cin >> D >> R >> T;
    tot_candle = R+T;
    while (theo_age+D > rita_age)
        rita_candle += rita_age++;
    
    while (rita_candle+theo_candle < tot_candle) {
        rita_candle += rita_age++;
        theo_candle += theo_age++;
    }
    cout << R-rita_candle << '\n';
    return 0;
}