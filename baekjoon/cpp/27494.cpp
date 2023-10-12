#include <iostream>
using namespace std;

int main() {
    int N, cnt=0, MMXXIII[4]={3,2,0,2};
    cin >> N;
    for (int i=2023; i<=N; i++) {
        int cur = 0, tmp = i;
        while (tmp && cur<4) {
            if (tmp%10==MMXXIII[cur]) cur++;
            tmp /= 10;
        }
        if (cur==4) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}