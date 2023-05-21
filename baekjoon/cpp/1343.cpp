#include <iostream>
using namespace std;

int main() {
    string map;
    cin >> map;
    int sz = map.size();
    for (int i=0; i<sz; i++) {
        if (i+1<sz && map[i]=='X' && map[i+1]=='X') {
            if (i+2<sz && i+3<sz && map[i+2]=='X' && map[i+3]=='X') {
                map[i] = 'A';
                map[i+1] = 'A';
                map[i+2] = 'A';
                map[i+3] = 'A';
            } else {
                map[i] = 'B';
                map[i+1] = 'B';
            }
        }
        if (map[i]=='X') {
            cout << "-1\n";
            return 0;
        }
    }
    cout << map << '\n';
    return 0;
}