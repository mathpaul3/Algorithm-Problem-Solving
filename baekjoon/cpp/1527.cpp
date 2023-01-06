#include <iostream>
using namespace std;

int A, B, cnt=0;

void KMS(long long cur) {
    if (cur >= A) cnt++;

    if (cur*10 + 4 <= B)
        KMS(cur*10 + 4);
    if (cur*10 + 7 <= B)
        KMS(cur*10 + 7);
}

int main() {
    cin >> A >> B;
    KMS(0);
    cout << cnt << '\n';

    return 0;
}