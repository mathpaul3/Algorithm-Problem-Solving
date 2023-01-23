#include <iostream>
using namespace std;

int line[21]={0,};

int main() {
    int N, k;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> k;
        cout << k << ' ';
        for (int j=1; j<=i; j++) {
            int num = k - line[j];
            if (j!=i) cout << num << ' ';
            line[j] = k;
            k = num;
        }
        cout << '\n';
    }
    return 0;
}