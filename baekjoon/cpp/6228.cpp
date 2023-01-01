#include <iostream>
using namespace std;
typedef unsigned long long int ll;

short N, S, E;
ll E_list[20][2];

ll combination(ll nums, ll local, short length, short prev, short cnt) {
    if (length == N) {
        for (short i=0; i<E; i++) {
            bool flag = true;
            for (short j=0; j<S; j++)
                if (E_list[i][1] & (ll)(1 << (j)*5) && (E_list[i][0] & (ll)(31 << (j)*5)) > (nums & (ll)(31 << (j)*5)))
                    flag = false;
            if (flag) return local/cnt;
        }
        return 0;
    }
    
    ll total = 0;
    for (short i=prev; i<=S; i++) {
        if (!i) continue;
        total += combination(nums + (ll)(1 << (i-1)*5), local/cnt, length+1, i, (prev == i ? cnt+1 : 1));
    }
    return total;
}

int main() {
    cin >> N >> S >> E;
    
    for (short i=0; i<E; i++) {
        int W, R;
        char times, plus='+';
        while (plus == '+') {
            scanf("%d%c%d%c", &W, &times, &R, &plus);
            
            E_list[i][0] += W * (ll)(1 << (R-1)*5);
            if (!(E_list[i][1] & (ll)(1 << (R-1)*5)))
                E_list[i][1] += (ll)(31 << (R-1)*5);
        }
    }

    ll factorial = 1;
    for (short i=2; i<=N; i++)
        factorial *= i;

    cout << combination(0, factorial, 0, 0, 1) << '\n';

    return 0;
}