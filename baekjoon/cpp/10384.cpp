#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    for (int i=1; i<=n; i++) {
        int alpha[26]={0,}, minimum = 100;
        string str;
        getline(cin, str);
        for (int i=0; i<str.size(); i++) {
            if ('A'<=str[i] && str[i]<='Z')
                alpha[str[i]-'A']++;
            else if ('a'<=str[i] && str[i]<='z')
                alpha[str[i]-'a']++;
        }
        
        for (int i=0; i<26; i++)
            if (alpha[i]<minimum)
                minimum = alpha[i];
        
        cout << "Case " << i << ": ";
        if (minimum==3) cout << "Triple pangram!!!\n";
        else if (minimum==2) cout << "Double pangram!!\n";
        else if (minimum==1) cout << "Pangram!\n";
        else cout << "Not a pangram\n";
    }
    return 0;
}