#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str, bomb;
    cin >> str;
    cin >> bomb;

    vector<char> remain;
    int s_size = str.size(), b_size = bomb.size();
    char bomb_last = bomb[b_size-1];
    for (int i=0; i<s_size; i++) {
        remain.push_back(str[i]);

        if ((remain.size() >= b_size)&&(str[i] == bomb_last)) {
            bool is_bomb = true;
            for (int j=0; j<b_size; j++) {
                if (remain[remain.size()-1-j] != bomb[b_size-1-j]) {
                    is_bomb = false;
                    break;
                }
            }
            if (is_bomb) {
                for (int j=0; j<b_size; j++) {
                    remain.pop_back();
                }
            }
        }
    }

    if (remain.empty()) {
        cout << "FRULA\n";
    } else {
        int size = remain.size();
        for (int i=0; i<size; i++) {
            cout << remain[i];
        }
        cout << '\n';
    }

    return 0;
}