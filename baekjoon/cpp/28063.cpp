#include <iostream>
using namespace std;

int main() {
    int N, x, y, cnt;
    cin >> N >> x >> y;
    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    } else {
        if (
            (x==1 && y==1) ||
            (x==1 && y==N) ||
            (x==N && y==1) ||
            (x==N && y==N)
        ) {
            cout << 2 << '\n';
            return 0;
        } else if (
            x==1 || y==1 || x==N || y==N
        ) {
            cout << 3 << '\n';
            return 0;
        }
        else {
            cout << 4 << '\n';
            return 0;
        }
    }
    return 0;
}