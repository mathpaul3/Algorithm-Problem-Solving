#include <iostream>
using namespace std;

int n, juice[10001]={0,}, dp[10001 ]={0,}, max_drink=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> juice[i];
    
    dp[1] = juice[1];
    dp[2] = dp[1] + juice[2];
    for (int i=3; i<=n; i++) {
        if (dp[i] < dp[i-1]) dp[i] = dp[i-1];
        if (dp[i] < juice[i] + juice[i-1] + dp[i-3]) dp[i] = juice[i] + juice[i-1] + dp[i-3];
        if (dp[i] < juice[i] + dp[i-2]) dp[i] = juice[i] + dp[i-2];
    }

    for (int i=1; i<=n; i++)
        max_drink = (max_drink < dp[i] ? dp[i] : max_drink);
    cout << max_drink << '\n';
    return 0;
}