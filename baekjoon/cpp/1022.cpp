#include <iostream>
using namespace std;

int beautiful(int i, int j) {
    int absi=(i<0?-i:i), absj=(j<0?-j:j);
    if (i<=0 && absi>=absj) return (1+2*absi)*(1+2*absi)-5*absi-j;
    else if (i>0 && absi>=absj) return (1+2*absi)*(1+2*absi)-absi+j;
    else if (j<0 && absj>absi) return (1+2*absj)*(1+2*absj)-3*absj+i;
    else if (j>0 && absj>absi) return (1+2*absj)*(1+2*absj)-7*absj-i;
}

int len(int num) {
    int nlen=0;
    while (num) { num/=10; nlen++; }
    return nlen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int r1, c1, r2, c2, max_len=0;
    cin >> r1 >> c1 >> r2 >> c2;
    max_len = max(len(beautiful(r1, c1)), max_len);
    max_len = max(len(beautiful(r1, c2)), max_len);
    max_len = max(len(beautiful(r2, c1)), max_len);
    max_len = max(len(beautiful(r2, c2)), max_len);

    for (int i=r1; i<=r2; i++) {
        for (int j=c1; j<=c2; j++) {
            int b_num=beautiful(i, j), b_num_len=len(b_num);
            while (max_len>b_num_len) { cout << ' '; b_num_len++; }
            cout << b_num << ' ';
        }
        cout << '\n';
    }
    return 0;
}