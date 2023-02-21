#include <iostream>
using namespace std;

int main() {
    short L;
    char c;
    long long hash=0, r=1;
    cin >> L;
    while (L--) {
        cin >> c;
        hash = (hash + (long long)(c-'`')*r) % 1234567891;
        r = (r*31) % 1234567891;
    }
    cout << hash << '\n';
    return 0;
}