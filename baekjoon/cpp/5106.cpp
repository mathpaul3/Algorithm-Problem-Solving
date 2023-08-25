#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    while (cin >> N) {
        if (!N) break;
        short alpha[26]={0,}, puzzle[26]={0,}, maximum=0, cnt=0;
        char the_word;
        string s;
        while (N--) {
            cin >> s;
            bool used[26]={0,};
            if (s.size()==9 && !puzzle[s[0]-'a'])
                for (int i=0; i<9; i++)
                    puzzle[s[i]-'a']++;
            for (int i=0; i<s.size(); i++) {
                if (used[s[i]-'a']) continue;
                else { alpha[s[i]-'a']++; used[s[i]-'a']=true; }
            }
        }
        for (int i=0; i<26; i++) {
            if (alpha[i]>maximum)
            { maximum = alpha[i]; the_word = i; }
        }
        puzzle[the_word]--;
        for (int i=0; i<26; i++) {
            while (puzzle[i]--) {
                cout << (char)(i+'A') << ' ';
                cnt++;
                if (cnt==4) cout << (char)(the_word+'A') << ' ';
            }
        }
    }
    return 0;
}