#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    while (b!=0) {
        ll r = a%b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }

    return 0;
}