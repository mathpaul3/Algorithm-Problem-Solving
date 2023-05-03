#include <iostream>
using namespace std;

int main() {
    int N, R1, C1, R2, C2;
    cin >> N >> R1 >> C1 >> R2 >> C2;
    for (int i=R1; i<=R2; i++) {
        for (int j=C1; j<=C2; j++) {
            int ydiff = (i)%(N*2-1)-(N-1), xdiff = (j)%(N*2-1)-(N-1);
            int chr = (ydiff<0?-ydiff:ydiff) + (xdiff<0?-xdiff:xdiff);
            cout << (char)(chr<N ? (chr%26)+97 : '.');
        }
        cout << '\n';
    }
    return 0;
}