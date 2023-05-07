#include <iostream>
using namespace std;

int main() {
    int D, K, fibo[50]={0,};
    cin >> D >> K;
    fibo[0]=1; fibo[1]=1;

    for (int i=2; i<50; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];

    int d1_coeff=fibo[D-3], d2_coeff=fibo[D-2];
    for (int d2=K/d2_coeff; d2>0; d2--) {
        int d1 = (K - d2_coeff*d2)/d1_coeff;
        if (d1 && (K == (d1_coeff*d1 + d2_coeff*d2))) {
            cout << d1 << '\n' << d2 << '\n';
            break;
        }
    }

    return 0;
}