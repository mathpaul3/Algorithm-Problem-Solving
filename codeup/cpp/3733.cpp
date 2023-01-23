#include <iostream>
using namespace std;

int len[10000001]={0,}, max_num, M=0;

int find(long long num, int length) {
    if (num == 1) return length;
    if (num<10000001 && len[num]) return len[num]+length-1;
    else return find((num%2 ? 3*num+1 : num/2), length+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    for (int i=a; i<=b; i++) {
        len[i] = find(i, 1);
        if (len[i] > M) {
            M = len[i];
            max_num = i;
        }
    }
    cout << max_num << ' ' << M << '\n';
    return 0;
}