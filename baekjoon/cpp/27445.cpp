#include <iostream>
using namespace std;

int main() {
    int N, M, dist, rm=10000, cm=10000, r=1, c=1;
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> dist;
        if (rm>dist) {rm = dist; r=i;}
    }
    if (cm>dist) {cm=dist;}
    for (int i=2; i<=M; i++) {
        cin >> dist;
        if (cm>dist) {cm = dist; c=i;}
    }
    cout << r << ' ' << c << '\n';
    return 0;
}