#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<string> s;

int main() {
    int N;
    string str;
    cin >> N;
    while(N--) {
        cin >> str;
        string original_str = str;
        reverse(str.begin(), str.end());
        
        if (original_str == str)
            cout << str.size() << ' ' << str[str.size()/2];
        
        if (s.find(str) != s.end()) {
            cout << str.size() << ' ' << str[str.size()/2];
        }
        s.insert(original_str);
    }

    return 0;
}