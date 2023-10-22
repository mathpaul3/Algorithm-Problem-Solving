#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int N, Hours, Minutes, Seconds;
tuple<int,int,int> times[5000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> get<0>(times[i]) >> get<1>(times[i]) >> get<2>(times[i]);
    sort(times, times+N);
    for (int i=0; i<N; i++)
        cout << get<0>(times[i]) << ' ' << get<1>(times[i]) << ' ' << get<2>(times[i]) << '\n';
    return 0;
}