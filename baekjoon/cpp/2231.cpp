#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i=1; i<=1000000; i++) {
        int tmp = i, sum=i;
        while (tmp) {
            sum += tmp%10;
            tmp/=10;
        }
        if (sum==N) { cout << i << '\n'; return 0; }
    }
    cout << 0 << '\n';
    return 0;
}