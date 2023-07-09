#include <iostream>
#define DIV 1000000007
using namespace std;

long long num=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    for (int i=s.size()-1; i>=0; i--) {
        num <<= 1;
        if (s[i]=='O') num++;
        num %= DIV;
    }
    cout << num << '\n';
    return 0;
}