#include <iostream>
using namespace std;

int main() {
    int N, sub=6, cnt=1;
    cin >> N;
    N-=1;
    while (N>0) {
        cnt++;
        N -= sub;
        sub += 6;
    }
    cout << cnt << '\n';
    return 0;
}