#include <iostream>
using namespace std;

int main() {
    int K, fibo[46]={0,};
    cin >> K;
    fibo[1] = 1;
    for (int i=2; i<=K; i++)
        fibo[i] = fibo[i-1]+fibo[i-2];
    cout << fibo[K-1] << ' ' << fibo[K] << '\n';
    return 0;
}