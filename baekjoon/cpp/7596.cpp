#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, scene=1;
    while (cin >> n) {
        if (!n) break;
        string scenarios[200];
        cin.ignore();
        for (int i=0; i<n; i++) getline(cin, scenarios[i]);
        sort(scenarios, scenarios+n);
        cout << scene++ << '\n';
        for (int i=0; i<n; i++) cout << scenarios[i] << '\n';
    }
    return 0;
}