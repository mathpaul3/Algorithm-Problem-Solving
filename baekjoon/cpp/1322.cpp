#include <iostream>
#define ull unsigned long long
using namespace std;

int main() {
    int len=32, Kcur=0;
    ull X, Y=0, K;
    cin >> X >> K;
    while (!(K & ((ull)1 << --len)));
    len++; Y = X;
    for (int i=0; Kcur<len; i++)
        if (!(Y & ((ull)1 << i)))
            Y += ((K & ((ull)1<<Kcur))<<(i-Kcur++));
    cout << (Y^X) << '\n';
    return 0;
}