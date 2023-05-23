#include <iostream>
using namespace std;

int N, M, mission[6]={0,}, cnt=0;

void do_mission(int sum, int yesterday) {
    if ((yesterday>>3) == N) {
        if (sum>=M) cnt++;
        return;
    }
    yesterday += 1<<3;
    for (int i=0; i<6; i++) {
        if (yesterday & 1<<(i%3)) {
            do_mission(sum+mission[i]/2, yesterday);
        } else {
            do_mission(sum+mission[i], ((yesterday>>3)<<3) | 1<<(i%3));
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i<6; i++) {
        cin >> mission[i];
    }
    do_mission(0, 0);
    cout << cnt << '\n';
    return 0;
}