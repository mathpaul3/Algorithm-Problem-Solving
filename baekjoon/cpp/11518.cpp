#include <iostream>
#include <map>
using namespace std;

int W;
char alpha;
string alpha_to_morse[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i=0; i<26; i++)
        cin >> alpha >> alpha_to_morse[alpha-'A'];
    
    cin >> W;
    map<string,string> morses;
    string word, morse;
    for (int i=0; i<W; i++) {
        cin >> word;
        morse = "";
        for (int j=0; j<word.size(); j++)
            morse += alpha_to_morse[word[j]-'A'];
        morses[morse] = word;
    }

    while (cin >> W) {
        if (!W) break;
        string result = "";
        bool OOV = false;
        for (int i=0; i<W; i++) {
            cin >> word;
            if (OOV) continue;
            if (morses.find(word)!=morses.end()) {
                if (i)
                    result += ' ';
                result += morses[word];
            } else {
                result = word;
                OOV = true;
            }
        }
        if (OOV)
            cout << result << " not in dictionary.\n";
        else
            cout << result << '\n';
    }
    return 0;
}