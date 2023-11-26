#include <iostream>
using namespace std;

int N;
string base2, base3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> base2 >> base3;
    for (int i=0; i<base2.size(); i++) {
        N += (base2[i]-'0')<<(base2.size()-i-1);
    }
    for (int i=0; i<base2.size(); i++) {
        N -= (base2[i]-'0')<<(base2.size()-i-1);
        N += ((base2[i]-'0'+1)%2)<<(base2.size()-i-1);
        int tmp = N;
        int diff = 0;
        for (int j=base3.size()-1; j>=0; j--) {
            if (tmp%3!=(base3[j]-'0')) diff++;
            if (diff>2) break;
            tmp /= 3;
        }
        if (!tmp && diff==1) {cout << N << '\n'; return 0;}
        N -= ((base2[i]-'0'+1)%2)<<(base2.size()-i-1);
        N += (base2[i]-'0')<<(base2.size()-i-1);
    }
    return 0;
}