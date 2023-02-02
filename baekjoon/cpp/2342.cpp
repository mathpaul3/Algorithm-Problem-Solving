#include <iostream>
using namespace std;

int step[100000]={0,}, dp[5][5][100000]={0,}, cur=0;

int pwr(int from, int to) {
    if (from==to) return 1;
    switch (from) {
        case 0: return 2;
        case 1: return (to==3?4:3);
        case 2: return (to==4?4:3);
        case 3: return (to==1?4:3);
        case 4: return (to==2?4:3);
    }
}

int move(int left, int right, int n) {
    if (n == cur) return 0;
    int& num = dp[left][right][n];
    if (num) return num;
    return num = min(pwr(left, step[n])+move(step[n], right, n+1), pwr(right, step[n])+move(left, step[n], n+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> step[cur++];
        if (!step[cur-1]) break;
    }
    cur--;
    cout << move(0,0,0) << '\n';
    return 0;
}