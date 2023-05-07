#include <iostream>
using namespace std;

int find_parent(int i, int *religion) {
    if (religion[i] == i) return i;
    return religion[i] = find_parent(religion[i], religion);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int case_num = 1;
    while (true) {
        int n, m, cnt=0, religion[50001]={0,};
        cin >> n >> m;
        if (!n && !m) break;

        for (int i=1; i<=n; i++)
            religion[i] = i;

        while (m--) {
            int i, j;
            cin >> i >> j;
            i = find_parent(i, religion);
            j = find_parent(j, religion);
            if (i>j) { i ^= j; j ^= i; i ^= j; }
            religion[j] = i;
        }

        for (int i=1; i<=n; i++) {
            if (religion[i] == i)
                cnt++;
        }
        cout << "Case " << case_num << ": " << cnt << '\n';
        case_num++;
    }
    return 0;
}