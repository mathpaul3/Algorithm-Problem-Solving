#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, K, G;
    cin >> T;
    while (T--) {
        int baht=100, person=0;
        cin >> G >> K;
        while (baht<G) {
            baht += 100*K - 90;
            person++;
        }
        cout << person << '\n';
    }
    return 0;
}