#include <iostream>
using namespace std;

int main() {
    long long N, M, cnt=0;
    cin >> N >> M;
    M = N-M;
    for (int i=1; i<10; i++) {
        long long tmp=i;
        while (tmp<=N) {
            if (tmp>=M) cnt++;
            tmp = tmp*10 + i;
        }
    }
    cout << cnt << '\n';
    return 0;
}