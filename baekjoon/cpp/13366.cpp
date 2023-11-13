#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        string x;
        int digit_sum = 0;
        cin >> x;
        for (int i=0; i<x.size(); i++)
            digit_sum += x[i]-'0';
        cout << (digit_sum%9 ? "NO\n" : "YES\n");
    }
    return 0;
}