#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int bed;
    while (cin >> bed) {
        if (!bed) break;
        string s;
        bool tanning[26]={0,}, walked[26]={0,};
        int customer=0, ret=0;
        cin >> s;
        for (int i=0; i<s.size(); i++) {
            int person = s[i]-'A';
            if (walked[person]) walked[person] = false;
            else if (!tanning[person]) {
                tanning[person] = true;
                if (customer<bed) customer++;
                else { ret++; walked[person] = true; }
            }
            else { tanning[person] = false; customer--; }
        }
        if (ret) cout << ret << " customer(s) walked away.\n";
        else cout << "All customers tanned successfully.\n";
    }
    return 0;
}