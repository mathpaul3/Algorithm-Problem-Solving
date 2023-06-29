#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    char space;
    int N, horizontal=0, vertical=0, h_cnt, v_cnt[100]={0,};
    cin >> N;
    for (int i=0; i<N; i++) {
        h_cnt = 0;
        for (int j=0; j<N; j++) {
            cin >> space;
            if (space=='.') { h_cnt++; v_cnt[j]++; }
            else { h_cnt=0; v_cnt[j]=0; }
            if (h_cnt==2) horizontal++;
            if (v_cnt[j]==2) vertical++;
        }
    }
    cout << horizontal << ' ' << vertical << '\n';
    return 0;
}