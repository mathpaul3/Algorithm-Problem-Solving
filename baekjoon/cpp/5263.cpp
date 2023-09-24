#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k, Ci;
    unordered_map<int,short> id;
    cin >> n >> k;
    while (n--) {
        cin >> Ci;
        id[Ci] = (id[Ci]+1)%k;
    }
    for (auto it=id.begin(); it!=id.end(); it++) {
        if (it->second) {
            cout << it->first << '\n';
            break;
        }
    }
    return 0;
}