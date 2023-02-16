#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int X, cnt=0;
    cin >> X;
    bitset<8> bin(X);
    string s = bin.to_string();
    bool one_found=false;
    for (int i=0; i<8; i++) {
        if (!one_found && s[i]=='1') {
            one_found = true;
            cnt++;
        } else if (s[i]=='1') {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}