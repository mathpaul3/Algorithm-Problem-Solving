#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

bitset<100> bitmask[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, P, i, j, cnt=0;
    cin >> P >> T;
    while (cin >> i >> j)
        bitmask[i].set(j, 1);
    sort(bitmask+1, bitmask+P+1, [](const auto & lhs, const auto & rhs) {
        return lhs.to_string() < rhs.to_string();
    });
    for (i=2; i<=P; i++)
        if ((bitmask[i] ^ bitmask[i-1]) != 0)
            cnt++;
    cout << cnt+1 << '\n';
    return 0;
}