#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    while (N--) {
        string s;
        int sz, pivot;
        cin >> s;
        sz = s.size();
        for (int i=1; i<101; i++) {
            if (i*i==sz) {
                pivot=i;
                break;
            }
        }
        for (int i=pivot-1; i>=0; i--) {
            for (int j=0; j<pivot; j++) {
                cout << s[i+j*pivot];
            }
        }
        cout << '\n';
    }
    return 0;
}