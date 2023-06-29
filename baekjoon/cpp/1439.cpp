#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int zeros=0, ones=0;
    char prv, cur;

    cin >> prv;
    if (prv == '0') zeros++;
    else ones++;

    while (cin >> cur) {
        if (prv!=cur) {
            if (cur=='0') zeros++;
            else ones++;
        }
        prv = cur;
    }
    cout << (zeros<ones ? zeros : ones) << '\n';

    return 0;
}