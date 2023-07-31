#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s, ring;
    char c;
    int N, cur=0, cnt=0;
    cin >> s;
    cin >> N;
    while (N--) {
        bool flag;
        cin >> ring;
        for (int i=0; i<10; i++) {
            flag = true;
            for (int j=0; j<s.length(); j++) {
                if (ring[(i+j)%10] != s[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) break;
        }
        cnt += flag;
    }
    cout << cnt << '\n';
    return 0;
}