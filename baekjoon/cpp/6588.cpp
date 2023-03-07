#include <iostream>
#include <bitset>

using namespace std;

const int MAX = 1e6;

bitset<MAX> is_prime; // a bitset to store prime numbers

void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sieve();

    int n;
    while (cin >> n && n != 0) {
        bool found = false;
        for (int i = 3; i <= n / 2; i += 2) {
            if (is_prime[i] && is_prime[n - i]) {
                cout << n << " = " << i << " + " << n - i << '\n';
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}
