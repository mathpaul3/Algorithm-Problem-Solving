#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, cnt=0;
    string passport;
    unordered_map<string, bool> stolen;
    cin >> N;
    while (N--) {
        cin >> passport;
        stolen[passport] = true;
    }
    cin >> M;
    while (M--) {
        cin >> passport;
        if (stolen[passport])
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}