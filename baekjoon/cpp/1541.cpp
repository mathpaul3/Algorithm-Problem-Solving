#include <iostream>
using namespace std;

int main() {
    int sum=0, num;
    char op;
    bool has_minus = false;

    while (true) {
        scanf("%d%c", &num, &op);
        sum += (has_minus ? -num : num);
        if (op == '\n') break;
        if (op == '-') has_minus = true;
    }
    cout << sum << '\n';

    return 0;
}