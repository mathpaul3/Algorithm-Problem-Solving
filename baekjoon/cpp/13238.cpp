#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, price, minimum=100000, maximum=0, max_benefit=0;
    cin >> n;
    while (n--) {
        cin >> price;
        if (price < minimum) {
            minimum = price;
            maximum = price;
        }
        if (price > maximum) {
            maximum = price;
            if (max_benefit < maximum-minimum)
                max_benefit = maximum-minimum;
        }
    }
    cout << max_benefit << '\n';
    return 0;
}