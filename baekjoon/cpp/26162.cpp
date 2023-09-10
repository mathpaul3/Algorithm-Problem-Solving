#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, a, cur=0;
    int prime[30]={0,};
    bool atom[119]={0,};
    for (int i=2; i<119; i++) {
        bool flag = true;
        for (int j=2; j*j<=i; j++) {
            if (!(i%j)) { flag = false; break; }
        }
        if (flag) prime[cur++] = i;
    }
    for (int i=0; i<cur; i++)
        for (int j=i; j<cur; j++)
            if (prime[i]+prime[j]<119)
                atom[prime[i]+prime[j]] = true;
    cin >> N;
    while (N--) {
        cin >> a;
        cout << (atom[a] ? "Yes\n" : "No\n");
    }
    return 0;
}