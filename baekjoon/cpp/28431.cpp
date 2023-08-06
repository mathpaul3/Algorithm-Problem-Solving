#include <iostream>
using namespace std;

int main() {
    bool num[10]={0,};
    short tmp;
    for(int i=0; i<5; i++) {
        cin >> tmp;
        if (num[tmp]) num[tmp] = false;
        else num[tmp] = true;
    }
    for (int i=0; i<10; i++) {
        if (num[i]) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}