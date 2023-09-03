#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, cnt, min_dist=0x7FFFFFFF, arr[5000]={0,};
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for (int i=1; i<n; i++) {
        if (arr[i]-arr[i-1] == min_dist) cnt++;
        else if (arr[i]-arr[i-1]<min_dist) {
            min_dist = arr[i]-arr[i-1];
            cnt=1;
        }
    }
    cout << min_dist << ' ' << cnt << '\n';
    return 0;
}