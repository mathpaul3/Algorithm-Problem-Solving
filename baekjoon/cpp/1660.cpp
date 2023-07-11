#include <iostream>
#define LEN 121
#define MAX 2100000000
using namespace std;

int N, num[LEN]={0,}, dp[300001]={0,};
int main() {
    cin >> N;
    for (int i=1; i<LEN; i++)
        num[i] = i*(i+1)/2 + num[i-1];
    for (int i=1; i<=N; i++) dp[i] = MAX;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<LEN; j++) {
            int ball = num[j];
            if (ball>=i) {
                if (ball==i) dp[i] = 1;
                break;
            }
            dp[i] = (dp[i]<(dp[i-ball]+1) ? dp[i] : (dp[i-ball]+1));
        }
    }
    cout << dp[N] << '\n';
    return 0;
}