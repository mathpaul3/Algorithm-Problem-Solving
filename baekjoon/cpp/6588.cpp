#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

void init() {
    for (int i=2; i<1001000; i++) {
        int sz = prime.size();
        bool is_prime = true;
        for (int j=0; j<sz; j++) {
            if (!(i % prime[j])) {
                is_prime = false;
                break;
            }
            if (prime[j]*prime[j] >= i)
                break;
        }
        if (is_prime)
            prime.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();

    int n=1;
    while(n) {
        cin >> n;
        if (!n)
            break;

        int M = 0;
        while (prime[++M] < n)
            true;
        
        M--;
        bool found = false;
        for (int i=1; prime[i]<n; i++) {
            if (found)
                break;
            for (int j=M; i<=j; j--) {
                if ((prime[i] + prime[j]) == n) {
                    cout << n << " = " << prime[i] << " + " << prime[j] << '\n';
                    found = true;
                    break;
                }
            }
        }
        if (!found)
            cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}