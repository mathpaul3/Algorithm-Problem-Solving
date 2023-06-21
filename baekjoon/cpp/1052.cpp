#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N, K, cnt_1=0;
    bitset<32> b;
    cin >> N >> K;
    b = bitset<32>(N);
    for (int i=0; i<24; i++) if (b[i]) cnt_1++;
    for (int i=23; i>=0; i--) {
        if (b[i] && --cnt_1 && !(--K)) {
            cout << ((1<<i)-N%(1<<i)) << '\n';
            return 0;
        } 
    }
    cout << 0 << '\n';
    return 0;
}