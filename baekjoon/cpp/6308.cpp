#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int t=1; ; t++){
        int n, m, c, max_i=0, cur_i=0, device, consumption[21]={0,};
        bool is_on[21]={0,};
        cin >> n >> m >> c;
        if (!n && !m && !c) break;
        for (int i=1; i<=n; i++) cin >> consumption[i];
        for (int i=0; i<m; i++) {
            cin >> device;
            if ((is_on[device] = !is_on[device]))
                cur_i += consumption[device];
            else cur_i -= consumption[device];
            if (max_i < cur_i) max_i = cur_i;
        }
        cout << "Sequence " << t << '\n';
        if (max_i <= c) {
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " << max_i << " amperes.\n\n";
        } else
            cout << "Fuse was blown.\n\n";
    }
    return 0;
}