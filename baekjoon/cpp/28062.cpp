#include <iostream>
using namespace std;

int main() {
    int N, ai, sum=0, min_odd=0x7FFFFFFF;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> ai;
        if (ai%2 && min_odd>ai) {
            min_odd = ai;
        }
        sum += ai;
    }
    if (sum%2) sum-= min_odd;
    cout << sum << '\n';
    return 0;
}