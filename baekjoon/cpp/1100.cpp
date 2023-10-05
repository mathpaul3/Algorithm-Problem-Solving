#include <iostream>
using namespace std;

int main() {
    int cnt=0;
    char chr;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> chr;
            if (((!(i%2) && !(j%2)) || (i%2 && j%2)) && chr=='F') cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}