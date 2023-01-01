#include <iostream>
using namespace std;

int N, M;

void sequence(string s, int prev) {
    if (s.size() == M) {
        int sz = s.size();
        for (int i=0; i<sz; i++)
            cout << s[i] << (i == (M-1) ? '\n' : ' ');
        return;
    }

    for (int i=prev+1; i<=N; i++) {
        sequence(s+(char)(i+48), i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    sequence("", 0);
    return 0;
}