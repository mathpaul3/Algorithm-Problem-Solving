#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, f, s, t, M, m;
    int dp_max[3]={0,}, dp_min[3]={0,};

    cin >> N;
    cin >> dp_max[0] >> dp_max[1] >> dp_max[2];
    dp_min[0] = dp_max[0]; dp_min[1] = dp_max[1]; dp_min[2] = dp_max[2];

    while (--N) {
        cin >> f >> s >> t;
        int f_M=dp_max[0], s_M=dp_max[1], t_M=dp_max[2];
        int f_m=dp_min[0], s_m=dp_min[1], t_m=dp_min[2];
        dp_max[0] = max(f_M, s_M) + f;
        dp_min[0] = min(f_m, s_m) + f;
        dp_max[1] = max(f_M, max(s_M, t_M)) + s;
        dp_min[1] = min(f_m, min(s_m, t_m)) + s;
        dp_max[2] = max(s_M, t_M) + t;
        dp_min[2] = min(s_m, t_m) + t;
    }

    M = max(dp_max[0], max(dp_max[1], dp_max[2]));
    m = min(dp_min[0], min(dp_min[1], dp_min[2]));
    cout << M << ' ' << m << '\n';

    return 0;
}