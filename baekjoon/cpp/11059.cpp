#include <iostream>
using namespace std;

string number;
int len, cumsum[1001]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> number;
    len = number.size();
    for (int i=1; i<=len; i++) {
        cumsum[i] = number[i-1]-'0';
        if (i) cumsum[i] += cumsum[i-1];
    }
    for (int i=len/2; i>=0; i--) {
        for (int j=0; i*2+j<=len; j++) {
            if (cumsum[j+i]-cumsum[j] == cumsum[j+2*i]-cumsum[j+i]) {
                cout << i*2 << '\n';
                return 0;
            }
        }
    }
}