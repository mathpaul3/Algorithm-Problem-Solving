#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x, y, w, h, m=10000;
    cin >> x >> y >> w >> h;
    m = min(m, x);
    m = min(m, y);
    m = min(m, w-x);
    m = min(m, h-y);
    cout << m << '\n';
    return 0;
}