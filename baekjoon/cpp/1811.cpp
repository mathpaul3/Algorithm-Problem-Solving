#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string target, guess;
    while (cin >> target) {
        if (target=="#") break;
        cin >> guess;
        
        int black=0, grey=0, white=0, sz=target.size();
        int target_cnt[26]={0,};
        bool target_used[50]={0,}, guess_used[50]={0,};
        for (int i=0; i<sz; i++) {
            if (target[i]==guess[i]) { black++; target_used[i]=true; guess_used[i]=true; }
            else target_cnt[target[i]-'A']++;
        }
        for (int i=0; i<sz; i++) {
            if (!guess_used[i] && target_cnt[guess[i]-'A']) {
                if (0<i && !target_used[i-1] && target[i-1]==guess[i]) {
                    grey++; target_cnt[guess[i]-'A']--;
                    target_used[i-1]=true; guess_used[i]=true;
                } else if (i<sz-1 && !target_used[i+1] && target[i+1]==guess[i]) {
                    grey++; target_cnt[guess[i]-'A']--;
                    target_used[i+1]=true; guess_used[i]=true;
                }
            }
        }
        for (int i=0;i<sz; i++) {
            if (!guess_used[i] && target_cnt[guess[i]-'A']) {
                white++; target_cnt[guess[i]-'A']--;
            }
        }
        cout << guess << ": " << black << " black, " << grey << " grey, " << white << " white\n";
    }
    return 0;
}