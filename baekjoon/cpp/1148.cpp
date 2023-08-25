#include <iostream>
using namespace std;

short words[200000][26]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int word_cnt=0;
    string word;
    while (cin >> word) {
        if (word=="-") break;
        for (int i=0; i<word.size(); i++)
            words[word_cnt][word[i]-'A']++;
        word_cnt++;
    }
    while (cin >> word) {
        if (word=="#") break;
        int alpha[26]={0,}, alpha_cnt[26]={0,}, minimum=2000000, maximum=0;
        for (int i=0; i<9; i++) alpha_cnt[word[i]-'A']++;
        for (int i=0; i<9; i++) {
            if (alpha[word[i]-'A']) continue;
            for (int j=0; j<word_cnt; j++) {
                bool flag = true;
                if (!words[j][word[i]-'A']) continue;
                for (int k=0; k<26; k++) {
                    if (words[j][k]>alpha_cnt[k]) {
                        flag = false; break;
                    }
                }
                if (flag) alpha[word[i]-'A']++;
            }
            if (minimum>alpha[word[i]-'A']) minimum = alpha[word[i]-'A'];
            if (maximum<alpha[word[i]-'A']) maximum = alpha[word[i]-'A'];
        }
        int cnt=0;
        for (int i=0; i<26; i++) {
            if (alpha_cnt[i] && alpha[i]==minimum) {
                cout << (char)(i+'A');
                cnt++;
            }
        }
        cout << ' ' << minimum << ' ';
        cnt = 0;
        for (int i=0; i<26; i++) {
            if (alpha_cnt[i] && alpha[i]==maximum) {
                cout << (char)(i+'A');
                cnt++;
            }
        }
        cout << ' ' << maximum << '\n';
    }
    return 0;
}