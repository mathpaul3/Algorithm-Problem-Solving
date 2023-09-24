#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    while (cin >> N) {
        if (!N) break;
        int mary_odd=0, mary_even=0, john_odd=0, john_even=0, finger;
        for (int i=0; i<N; i++) {
            cin >> finger;
            if (finger%2) mary_odd++;
            else mary_even++;
        }
        for (int i=0; i<N; i++) {
            cin >> finger;
            if (finger%2) john_odd++;
            else john_even++;
        }
        cout << ((mary_odd-john_even>0 ? mary_odd-john_even : 0) + (mary_even-john_odd>0 ? mary_even-john_odd : 0)) << '\n';
    }
    return 0;
}