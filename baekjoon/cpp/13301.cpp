#include <iostream>
using namespace std;

int main() {
    int N;
    long long circumference=0, side_short=1, side_long=1;
    cin >> N;
    while (--N) {
        side_short += side_long;
        side_long ^= side_short;
        side_short ^= side_long;
        side_long ^= side_short;
    }
    cout << (side_short + side_long)*2 << '\n';

    return 0;
}