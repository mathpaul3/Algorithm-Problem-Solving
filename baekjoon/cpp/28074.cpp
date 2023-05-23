#include <iostream>
using namespace std;

bool alpha[26]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int sz = s.size();
    for (int i=0; i<sz; i++) {
        alpha[s[i]-'A'] = true;
    }

    if (
        alpha['M'-'A'] &&
        alpha['O'-'A'] &&
        alpha['B'-'A'] &&
        alpha['I'-'A'] &&
        alpha['S'-'A']
    ) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}