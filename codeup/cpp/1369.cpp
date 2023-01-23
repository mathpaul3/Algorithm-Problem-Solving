#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, nn, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) cout << '*';
    cout << '\n';
    int cur=k-1;
    for (int i=0; i<n-2; i++) {
        string s = "*";
        for (int j=2; j<=n-1; j++)
            if (j%k == cur) s += '*';
            else s += ' ';
        s += '*';
        if (!(cur--)) cur = k-1;
        cout << s << '\n';
    }
    if (n > 1)
        for (int i=0; i<n; i++) cout << '*';
    cout << '\n';
    return 0;
}