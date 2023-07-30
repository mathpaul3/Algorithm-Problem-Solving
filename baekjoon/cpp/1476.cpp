#include <iostream>
using namespace std;

int main() {
    int E, S, M, year;
    cin >> E >> S >> M;
    year = E;
    E %= 15; S %= 28; M %= 19;
    while (year%15!=E || year%28!=S || year%19!=M) {
        year += 15;
    }
    cout << year << '\n';
    return 0;
}