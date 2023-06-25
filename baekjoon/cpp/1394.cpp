#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int sz, psz, mul=1, cnt=0, mod=900528;
    string s, password;
    map<char,int> ord;
    cin >> s >> password;

    sz = s.size();
    for (int i=0; i<sz; i++) ord[s[i]] = i+1;

    psz = password.size();
    for (int i=1; i<=psz; i++) {
        cnt = (cnt+ord[password[psz-i]]*mul) % mod;
        mul = (mul%mod*sz) % mod;
    }
    cout << cnt << '\n';

    return 0;
}