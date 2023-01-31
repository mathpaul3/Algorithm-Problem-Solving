#include <iostream>
using namespace std;

int prime[100000]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int A, B;
    cin >> A >> B;
    int cur=0;
    for (int i=2; i<=B; i++) {
        bool flag=true;
        for (int j=0; j<cur; j++) {
            if (prime[j] && !(i%prime[j])) { flag=false; break; }
        }
        if (!flag) continue;
        prime[cur++] = i;
    }
    int under_prime=0;
    for (int i=A; i<=B; i++) {
        int prime_factor=0, X=i;
        cur=0;
        while (X != 1) {
            if (X%prime[cur]) cur++;
            else {prime_factor++; X/=prime[cur];}
        }
        cur=0;
        while (true) {
            if (prime_factor == prime[cur]) {under_prime++; break;}
            if (prime_factor < prime[cur]) break;
            cur++;
        }
    }
    cout << under_prime << '\n';
    return 0;
}