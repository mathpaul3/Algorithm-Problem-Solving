#include <iostream>
using namespace std;

long long N, K, curY=1, curX=1;
long long sum=1;
string s;

long long getNum(long long i, long long j) {
    if (i+j-1<=N) {
        long long diagM = (i+j)*(i+j-1)/2;
        if ((i%2 ^ j%2)) return diagM-(j-1);
        else return diagM-(i-1);
    } else {
        long long diagm = N*N - (2*N-i-j+2)*(2*N-i-j+1)/2 + 1;
        if (((N-i)%2 ^ (N-j)%2)) return diagm + (N-j);
        else return diagm + (N-i);
    }
}

int main() {
    cin >> N >> K >> s;
    for (int i=0; i<s.size(); i++) {
        switch (s[i]) {
            case 'D': curY++; break;
            case 'U': curY--; break;
            case 'L': curX--; break;
            case 'R': curX++; break;
        }
        sum += getNum(curY, curX);
    }
    cout << sum << '\n';
    return 0;
}