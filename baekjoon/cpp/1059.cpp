#include <iostream>
#include <algorithm>
using namespace std;

int S[50], L, n, A=0, B=1001, i, j, cnt=0;
int main() {
    cin >> L;
    for (i=0; i<L; i++) cin >> S[i];
    cin >> n;
    sort(S, S+L);
    i=0;   while (n>=S[i]) A = S[i++]; A++;
    i=L-1; while (n<=S[i]) B = S[i--]; B--;
    for (i=A; i<=n; i++)
        for (j=n; j<=B; j++)
            if ((i!=j)) cnt++;
    cout << cnt << '\n';
    return 0;
}