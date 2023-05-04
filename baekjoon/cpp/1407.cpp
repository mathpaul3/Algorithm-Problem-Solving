#include <iostream>
using namespace std;

int main() {
    unsigned long long A, B, sum=0, div=0x8000000000000000;
    long long cur, prev=0;
    int i=0;
    cin >> A >> B;
    while (div) {
        cur = B/div - A/div + (A%div?0:1);
        sum += (cur-prev)*div;
        prev = cur;
        div >>= 1;
    }
    cout << sum << '\n';

    return 0;
}