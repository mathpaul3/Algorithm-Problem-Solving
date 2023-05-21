#include <iostream>
using namespace std;

int main() {
    long long S;
    cin >> S;
    for (int i=1; ; i++) {
        S -= i;
        if (S<0) {
            cout << i-1 << '\n';
            return 0;
        } else if (S==0) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}