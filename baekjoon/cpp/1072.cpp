#include <iostream>
using namespace std;

int X, Y;
long long Z;
int find(int left, int right) {
    if (left == right) return left;
    int mid = (left+right) / 2;
    long long cur_Z = 100*(long long)(Y+mid)/(X+mid);
    if (Z==cur_Z) return find(mid+1, right);
    if (Z<cur_Z) return find(left, mid);
}

int main() {
    cin >> X >> Y;
    Z = 100*(long long)Y/X;
    if (Z > 98) {
        cout << -1 << '\n';
        return 0;
    }
    cout << find(0, 1000000000) << '\n';
    return 0;
}