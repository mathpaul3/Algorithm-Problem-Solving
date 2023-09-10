#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, source, destination, start, duration;
    while (cin >> N >> M) {
        if (!N && !M) break;
        int cnt = 0;
        vector<pair<int,bool> > call;
        for (int i=0; i<N; i++) {
            cin >> source >> destination >> start >> duration;
            call.push_back(make_pair(start, true));
            call.push_back(make_pair(start+duration, false));
        }
        sort(call.begin(), call.end());
        while (M--) {
            int time, id, cnt=0;
            bool is_start, flag=false;
            cin >> start >> duration;
            for (int i=0; i<N*2; i++) {
                tie(time, is_start) = call[i];
                if (time>=start+duration) break;
                if (time<=start) (is_start ? cnt++ : cnt--);
                else if (is_start) cnt++;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}