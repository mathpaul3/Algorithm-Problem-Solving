#include <iostream>
using namespace std;

short n, binary=1, complement=20000, arr[10001]={0,};
int main() {
    cin >> n;
    while (binary<=n) binary <<= 1;
    for (short i=n; i; i--) {
        if (complement>i) {
            while (binary/2>i) binary >>= 1;
            complement = binary-i;
        }
        arr[i] = binary - i;
    }
    for (short i=1; i<=n; i++)
        cout << arr[i] << '\n';
    return 0;
}