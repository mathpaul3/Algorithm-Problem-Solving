#include <iostream>
using namespace std;

int main() {
    int N;
    long long sum=0, square=0, cube=0;
    cin >> N;
    for (int i=1; i<=N; i++) {
        sum += i;
        cube += i*i*i;
    }
    cout << sum << '\n';
    cout << sum*sum << '\n';
    cout << cube << '\n';
    return 0;
}