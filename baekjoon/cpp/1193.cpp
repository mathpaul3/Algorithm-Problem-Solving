#include <iostream>
using namespace std;

int main() {
    int X, i=0, sum=0;
    cin >> X;
    while (sum<X) {
        sum += ++i;
    }
    sum -= i++;
    if (i%2) cout << i-(i-(X-sum)) << '/' << i-(X-sum) << '\n';
    else cout << i-(X-sum) << '/' << i-(i-(X-sum)) << '\n';
    return 0;
}