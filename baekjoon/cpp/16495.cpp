#include <iostream>
#include <string>
using namespace std;

int main() {
    int i;
    long long cnt=0, r=1;
    string s;
    cin >> s;

    for (i=s.length()-1; i>=0; i--)
    {
        cnt += ((int)s[i] - 64) * r;
        r *= 26;
    }

    cout << cnt;
    return 0;
}