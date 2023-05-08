#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        int Ti, M=0;
        long long N, Nij;
        unordered_map<long long,int> Ni;
        cin >> Ti;
        for (int i=0; i<Ti; i++) {
            cin >> Nij;
            unordered_map<long long,int>::iterator it = Ni.find(Nij);
            if (it == Ni.end()) {
                Ni.insert(make_pair(Nij, 1));
                if (M<1) {
                    N = Nij;
                    M = 1;
                }
            } else {
                it->second++;
                if (M < it->second) {
                    N = it->first;
                    M = it->second;
                }
            }
        }
        if (M>(Ti/2)) {
            cout << N << '\n';
        } else {
            cout << "SYJKGW\n";
        }
    }
    return 0;
}