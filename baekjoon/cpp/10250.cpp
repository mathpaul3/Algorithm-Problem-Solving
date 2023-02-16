#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, H, W, N;
    cin >> T;
    while (T--) {
        cin >> H >> W >> N;
        cout << setfill('0') << (N%H ? N%H : H) << setw(2) << (N%H ? (N/H)+1 : N/H) << '\n';
    }
    return 0;
}