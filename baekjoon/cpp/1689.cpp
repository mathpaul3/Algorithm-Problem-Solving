#include <iostream>
#include <algorithm>
using namespace std;

pair<int,bool> arr[2000000];
int cnt=0, max_cnt=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[2*i].first >> arr[2*i+1].first;
        arr[2*i].second = true;
    }
    sort(arr, arr+2*N);
    for (int i=0; i<2*N; i++) {
        if (arr[i].second) {
            cnt++;
            if (max_cnt<cnt) max_cnt = cnt;
        } else cnt--;
    }
    cout << max_cnt << '\n';
    return 0;
}