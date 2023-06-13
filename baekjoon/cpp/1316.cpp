#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, group_word=0;
    cin >> N;
    while (N--) {
        bool alpha[26]={0,}, is_group_word=true;
        int sz;
        string s;
        cin >> s; sz = s.size();
        for (int i=0; i<sz; i++) {
            if (i==0) alpha[s[i]-'a'] = true;
            if (i>0 && s[i]!=s[i-1]) {
                if (alpha[s[i]-'a']) {
                    is_group_word = false;
                    break;
                }
                else alpha[s[i]-'a'] = true;
            }
        }
        group_word += is_group_word;
    }
    cout << group_word << '\n';
    return 0;
}