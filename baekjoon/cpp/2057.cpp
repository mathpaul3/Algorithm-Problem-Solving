#include <iostream>
using namespace std;

long long N, tmp=1, arr[21]={0,}, mask=1;

bool check_comb(int m) {
    long long sum=0;
    for (int i=0; i<21; i++)
        if ((m & (1<<i)))
            sum += arr[i];
    return N==sum;
}

int main() {
    cin >> N;
    for (int i=0; i<21; i++) {
        if (i==0) arr[i] = 1;
        else arr[i] = tmp*=i;
        if (arr[i]<=N) mask <<= 1;
    }
    while (--mask) {
        if (check_comb(mask)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}