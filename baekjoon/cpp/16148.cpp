#include <iostream>
#include <algorithm>
using namespace std;

int K, n, i, threshold[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> K;
    for (int t=1; t<=K; t++) {
        cin >> n;
        for (i=0; i<n; i++)
            cin >> threshold[i];
        sort(threshold, threshold+n);

        for (i=0; threshold[i]<=i && i<n; i++) {}
        cout << "Data Set " << t << ":\n" << i << "\n\n";
    }
    return 0;
}