#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, now, fin;
    cin >> A >> B >> C >> D;
    now = ((A*60)+B)*60+C;
    fin = now + D;
    cout << (fin/60/60)%24 << ' ' << (fin/60)%60 << ' ' << fin%60 << '\n';
    return 0;
}