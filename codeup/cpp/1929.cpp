#include <iostream>
using namespace std;

void collatz(int num) {
    if (num == 1) {
        cout << num << '\n';
        return;
    }
    collatz((num%2 ? 3*num+1 : num/2));
    cout << num << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    collatz(n);
    return 0;
}