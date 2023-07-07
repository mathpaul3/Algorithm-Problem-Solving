#include <iostream>
#define DIV 1000000007
using namespace std;

long long N, C, K;
long long sum=0;

long long fpow(int a, int n) {
    if (n == 0) return 1;
    if (n%2) {
        long long half = fpow(a, n-1);
        return (a*half)%DIV;
    } else {
        long long tmp = fpow(a, n/2);
        return (tmp*tmp)%DIV;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> C >> K;
        if (K==0) continue;
        sum = (sum + ((C*K)%DIV)*fpow(2, K-1)) % DIV;
    }
    cout << sum << '\n';
    return 0;
}