#include <iostream>
using namespace std;

int main() {
    int N, small=1, big=1, sum=1, cnt=0;
    cin >> N;
    
    while (small<=N) {
        if (sum<N) {
            sum += ++big;
        } else {
            if (sum == N) {
                cnt++;
            }
            sum -= small++;
        }
    }
    cout << cnt << '\n';

    return 0;
}