#include <iostream>
using namespace std;

int N, five=0, three=0;

int main() {
    cin >> N;
    five += N/5;
    if (N%5) five++;
    else {cout << five << '\n'; return 0;}

    bool possible=false;
    while (five--) {
        if (!((N-five*5)%3)) {cout << five+(N-five*5)/3 << '\n'; return 0;}
    }
    cout << "-1\n";

    return 0;
}