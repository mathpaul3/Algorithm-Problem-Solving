#include <iostream>
#include <map>
using namespace std;

int M, N;
char key[]={0, ' ', 'A', 'D', 'G', 'J', 'M', 'P', 'T', 'W'};
map<string, string> dict;
string ans;

char to_num(char c) {
    c -= 'A';
    if (c < 'R'-'A') return c/3 + 2;
    else if (c < 'Y'-'A') return (c-1)/3 + 2;
    else return 9;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M;
    for (int i=0; i<M; i++) {
        string word, dict_key;
        cin >> word;
        for (int i=0; i<word.size(); i++)
            dict_key += key[to_num(word[i])];
        if (dict.find(dict_key)==dict.end())
            dict[dict_key] = word;
    }
    cin >> N;
    int pressed_key;
    string word;
    for (int i=0; i<N; i++) {
        cin >> pressed_key;
        if (pressed_key==1) {
            if (word!="") {
                if (dict.find(word)!=dict.end())
                    ans += dict[word];
                else for (int i=0; i<word.size(); i++) ans += '*';
            }
            ans += ' ';
            word = "";
        } else word += key[pressed_key];
    }
    if (word!="") {
        if (dict.find(word)!=dict.end())
            ans += dict[word];
        else for (int i=0; i<word.size(); i++) ans += '*';
    }
    cout << ans << '\n';
    return 0;
}