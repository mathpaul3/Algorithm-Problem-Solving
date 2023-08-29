#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int C, N, Q, maxClen=0, maxNlen=0, idx;
string input;
unordered_set<string> nickname;

class Color {
public:
    bool eow;
    Color* alpha[26]={0,};
    Color() { eow=false; }
    void insert(char *c) {
        if (!(*c)) eow = true;
        else {
            if (!alpha[(*c)-'a']) alpha[(*c)-'a'] = new Color();
            alpha[(*c)-'a']->insert(c+1);
        }
    }
    bool search(char *c) {
        ++idx;
        if (!(*c)) return false;
        if (eow && maxNlen>=input.size()-idx && nickname.find(input.substr(idx-1))!=nickname.end()) return true;
        if (alpha[(*c)-'a'] && alpha[(*c)-'a']->search(c+1)) return true;
        return false;
    }
};
Color c;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> C >> N;
    while (C--) {
        cin >> input;
        c.insert(&input[0]);
        if (maxClen<input.size()) maxClen = input.size();
    }
    while (N--) {
        cin >> input;
        nickname.insert(input);
        if (maxNlen<input.size()) maxNlen = input.size();
    }
    cin >> Q;
    while (Q--) {
        cin >> input;
        idx = 0;
        if (input.size()>maxClen+maxNlen) cout << "No\n";
        else cout << (c.search(&input[0]) ? "Yes\n" : "No\n");
    }
    return 0;
}